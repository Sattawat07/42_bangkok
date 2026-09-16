*This project has been created as part of the 42 curriculum by sboontem.*

## Description

This project recreates the basic functionality of `printf` to help understand variadic functions: functions that accept a variable number of arguments. It introduces `va_list` and the macros used to access those arguments.

The project builds a static library called `libftprintf.a` and supports `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.

The source files are divided by responsibility:

- **ft_printf.c:** Contains the main function. It reads the format string character by character, prints ordinary characters directly, and uses `matchf` to select the correct helper after `%`. It handles `%%` directly and tracks the output count.
- **ft_print_chars.c:** Prints characters and strings for `%c` and `%s`.
- **ft_print_numbers.c:** Prints decimal numbers for `%d`, `%i`, and `%u`.
- **ft_print_hex.c:** Prints hexadecimal numbers and pointers for `%x`, `%X`, and `%p`.

## Instructions

Use a Unix-like environment with `cc`, `make`, and `ar`. Run these commands from the project directory:

- `make` or `make all`: Builds `libftprintf.a`.
- `make clean`: Removes object files while keeping the library.
- `make fclean`: Removes object files and the library.
- `make re`: Rebuilds the project from scratch.

Compile and run:

```sh
make && make clean
cc ft_printf.c libftprintf.a -I. -o printf_demo
./printf_demo
```

## Algorithm and Technical Choices

Numbers are converted using a fixed-size local character buffer. Each digit is obtained with `% 10` or `% 16`, stored in the buffer, and removed from the number using division. The buffer is then read backward to print the digits in the correct order. For example, `123` is stored as `3, 2, 1` and printed as `123`. Zero is handled separately, and signs and pointer prefixes are printed before the digits.

I chose iteration to avoid recursive calls for each digit and keep the conversion easy to follow. The buffer still uses stack memory, but it avoids nested conversion calls and does not require heap allocation.

My first approach used a divisor to extract digits from left to right. In `ft_putptr`, repeatedly multiplying the divisor by 16 caused overflow for large values. I replaced this approach with a buffer because dividing the input avoids the growing divisor and makes the code easier to write and debug.

The buffers must be large enough for the supported types. The current code assumes 32-bit integers and a 64-bit `long` capable of holding a pointer, as on typical 64-bit Linux systems. It reserves 10 bytes for decimal digits and 16 for pointer digits. These buffers are printed by index, so they do not need a null terminator.

## Undefined Behavior

The subject makes an exception for undefined behavior in its rule against unexpected crashes. This means there is no required portable result to match when the corresponding standard `printf` call itself has undefined behavior. It does not excuse bugs on valid inputs.

Examples include:

- Missing arguments, such as `printf("%d %d", 42)`.
- Incorrect argument types, such as `printf("%d", 3.14)`.
- A null or invalid format pointer.
- An invalid string pointer, or a string without an accessible null terminator, passed to `%s`.
- An incomplete conversion, such as a trailing `%`, or an invalid conversion such as `%Q`.

This implementation prints `(null)` for a null `%s` argument as an extra safeguard. A null pointer passed as `(void *)0` to `%p` is valid and prints `(nil)` here. Empty strings, zero, and integer limits are also valid cases that must be handled.

## Resources

- [printf manual](https://man7.org/linux/man-pages/man3/printf.3.html): Conversions and return values.
- [stdarg manual](https://man7.org/linux/man-pages/man3/stdarg.3.html): Variadic arguments and related macros.
- [C11 draft, sections 7.1.4 and 7.21.6.1](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf): Undefined behavior and formatted output.
- Google, GitHub, and YouTube for explanations and learning material.

**AI Usage:** AI was used to look up information and help investigate bugs when I was stuck. It also helped translate and simplify this README, explain the buffer approach, and clarify undefined behavior.
