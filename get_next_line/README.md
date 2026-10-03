*This project has been created as part of the 42 curriculum by sboontem.*

# Get Next Line

## Description

`get_next_line(int fd)` returns one line from a file descriptor per call. The
returned string includes the terminating newline when one is present. At the end
of the input, or on an error, the function returns `NULL`. It works with regular
files and standard input, including pipes. The caller must `free()` each returned
line.

This repository contains the mandatory part of the 42 Get Next Line project.
It keeps one static remainder, so calls should read one file descriptor through
to completion before switching to another. Interleaved file descriptors are a
bonus requirement and are not implemented here.

## Instructions

The project provides a function, not a standalone program. Compile it with a
program that calls `get_next_line`:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
  get_next_line.c get_next_line_utils.c main.c -o gnl_demo
./gnl_demo
```

`main.c` is your own test program. Include `get_next_line.h`, call
`get_next_line(fd)` repeatedly until it returns `NULL`, and free each line.
You may omit `-D BUFFER_SIZE=42`; the header defaults to 42. The function also
supports other positive buffer sizes, including 1.

## Algorithm

One static pointer holds bytes read after the most recently returned newline.
On each call, the function first checks whether that remainder already contains
a complete line. If so, it returns that line without reading again. Otherwise,
it reads chunks of `BUFFER_SIZE` bytes and appends them to a dynamically grown
string until a newline or EOF is reached. The allocation capacity doubles as
needed, avoiding a new allocation and copy for every chunk of a long line.

The function copies the first complete line into a caller-owned string, then
keeps only the unreturned bytes for the next call. It frees temporary storage
on EOF and error. Reading stops at the first chunk containing a newline, which
keeps it usable with pipes and standard input where more data may arrive later.

## Resources

- `subject`: project requirements and evaluation scope.
- `man 2 read`: file descriptor reads, EOF, and errors.
- `man 3 malloc` and `man 3 free`: allocation and ownership.

AI was used to look up information and help investigate bugs when I was stuck. It also helped translate and simplify this README.
