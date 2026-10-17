*This project has been created as part of the 42 curriculum by sboontem.*

# Get Next Line

## Description

`get_next_line(int fd)` returns one line from a file descriptor on each call.
The returned string includes the terminating `\n` when present. The last line
may end without a newline. The function returns `NULL` when there is nothing
left to read or an error occurs.

This project implements the mandatory part. It uses one static pointer to keep
unreturned data between calls and supports text files and standard input,
including pipes. Read one file descriptor through to EOF before switching to
another; interleaved reading from multiple descriptors is not implemented.

The caller owns each returned line and must free it after use.

## Project Files

| File | Purpose |
| --- | --- |
| `get_next_line.c` | Reading, extracting a line, and saving the remainder. |
| `get_next_line_utils.c` | String helpers, memory copying, and buffer growth. |
| `get_next_line.h` | Shared prototypes, includes, and the default buffer size. |

## Instructions

Use a C compiler such as `cc` in a Linux or WSL environment. This project
provides a function, so a separate test program is needed to run it.

### Example main.c

Create `main.c` at the root of the project with the following content.
This file is for local testing and is not part of the required submission.

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (printf("can't open file\n"), 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

The program opens `test.txt`, prints and frees each returned line, then closes
the file. It does not add another newline because the returned line already
includes one when present in the input.

### Compile and Run

Create an initial test file:

```sh
printf 'ABC\nDEF\nXY' > test.txt
```

Compile and run:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=5 \
  get_next_line.c get_next_line_utils.c main.c -o test_gnl
./test_gnl
```

The output should match the file contents. In this example, `XY` has no final
newline, so the shell prompt may appear immediately after it.

`BUFFER_SIZE` controls the maximum number of bytes requested by each data read;
it does not limit the length of a returned line. If `-D BUFFER_SIZE=5` is omitted,
the header defines a default value of `42`.

## Testing

Choose one case below, then run `./test_gnl`. Each `>` command overwrites
`test.txt`, so run the program after each case before creating the next one.

### Multiple Lines Without a Final Newline

```sh
printf 'ABC\nDEF\nXY' > test.txt
./test_gnl
```

Expected calls: `"ABC\n"`, `"DEF\n"`, `"XY"`, then `NULL`.

### Empty File

```sh
printf '' > test.txt
./test_gnl
```

Expected: no output; the first call returns `NULL`.

### Two Empty Lines

```sh
printf '\n\n' > test.txt
./test_gnl
```

Expected calls: `"\n"`, `"\n"`, then `NULL`.

### Text Without a Newline

```sh
printf 'Hello' > test.txt
./test_gnl
```

Expected calls: `"Hello"`, then `NULL`.

### Text With a Final Newline

```sh
printf 'Hello\n' > test.txt
./test_gnl
```

Expected calls: `"Hello\n"`, then `NULL`. A final newline does not create an
additional empty line.

### Different Buffer Sizes

Recompile with other positive sizes, such as `1`, `42`, `9999`, or `10000000`.
Changing `BUFFER_SIZE` requires recompiling; editing `test.txt` does not.

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 \
  get_next_line.c get_next_line_utils.c main.c -o test_gnl
./test_gnl
```

These examples provide a basic visual check. Matching printed output alone does
not verify line boundaries or memory safety. Further tests should compare each
returned string, check repeated calls after EOF and invalid descriptors, and
exercise long lines, standard input, read errors, and allocation failures.

## Algorithm and Design Choices

1. **Validate the input.** Reject negative descriptors and non-positive buffer
   sizes. A zero-byte `read()` checks for descriptor errors without consuming
   input; actual data reads are also checked for errors.
2. **Reuse saved data.** A static pointer keeps bytes left after the previously
   returned line. If they already contain a newline, no additional input data
   is read.
3. **Read until a line is available or EOF is reached.** Read chunks of up to
   `BUFFER_SIZE` bytes, append a null terminator, and join them to the accumulated
   text. Stop after the first chunk containing a newline, or when `read()` returns
   zero. A read error releases the accumulated text and returns `NULL`.
4. **Extract the result.** Allocate a separate string containing the first line,
   including its newline if present. At EOF, return any remaining text even if
   it has no newline.
5. **Save the remainder.** Copy bytes after the first newline into a new allocation
   and free the old accumulated text. If there is no remainder, clear the static
   pointer. Allocation failures are propagated as errors, with owned memory
   released along the relevant error path.

### Why a Static Pointer?

A single read can contain part of the next line. The static pointer preserves
those extra bytes between calls, while the operating system maintains the file
position. For example, reading `"ABC\nD"` returns `"ABC\n"` and saves `"D"` for
the next call.

### Why Grow the Allocation Geometrically?

While accumulating a line, the code tracks both its length and its allocation
capacity. When more space is needed, it doubles the capacity until the incoming
chunk fits. This reduces repeated allocations and copying compared with growing
the string by exactly one chunk each time, especially for long lines and small
buffer sizes. Capacity tracking is local to each reading pass.

The code also checks size arithmetic before joining strings and guards capacity
doubling against overflow. Extracting the returned line and copying the remainder
require additional allocations and copies; this keeps their ownership separate
and straightforward.

### Why Static Helper Functions?

Helpers used only inside one source file are declared `static` to keep them local
to that file. Helpers shared between the two source files have prototypes in
`get_next_line.h`. Function-level `static` controls visibility; the static local
pointer in `get_next_line()` instead preserves state between calls.

## Resources

- The Get Next Line subject, version 14.3: requirements and evaluation scope.
- `man 2 read`: reading from file descriptors, return values, EOF, and errors.
- `man 2 open` and `man 2 close`: opening and closing test files.
- `man 3 malloc` and `man 3 free`: allocation and memory ownership.

### AI Use

AI was used to look up information and help investigate bugs when I was stuck. It also helped translate and simplify this README.
