# _printf

A custom implementation of the C standard library printf function, built as part of the Holberton School curriculum.

## Description

_printf replicates the core behavior of the standard printf function. It writes formatted output to stdout and returns the number of characters printed (excluding the null byte). Internally it uses a local buffer of 1024 bytes (`BUF_SIZE`) to minimize calls to write.

## Prototype
int _printf(const char *format, ...);

## Compilation
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o printf

## Supported Conversion Specifiers

| Specifier | Description |
|-----------|-------------|
| %c | Prints a single character |
| %s | Prints a string |
| %% | Prints a literal % character |
| %d | Prints a decimal integer |
| %i | Prints an integer |
| %u | Prints an unsigned integer |
| %o | Prints an integer in octal |
| %x | Prints an integer in lowercase hexadecimal |
| %X | Prints an integer in uppercase hexadecimal |
| %b | Prints an unsigned integer in binary *(custom)* |
| %S | Prints a string; non-printable characters are printed as \x followed by their ASCII hex value *(custom)* |

> Note: Flag characters, field width, precision, and length modifiers are not handled.

## Return Value

Returns the total number of characters printed (excluding the null byte). Returns -1 if format is NULL or if the format string ends with a lone %.

## Examples
_printf("Hello, %s!\n", "world");        // Hello, world!
_printf("Number: %d\n", 42);             // Number: 42
_printf("Binary: %b\n", 98);             // Binary: 1100010
_printf("Hex: %x\n", 255);              // Hex: ff
_printf("Special: %S\n", "Best\nSchool"); // Special: Best\x0ASchool

## Files

| File | Description |
|------|-------------|
| _printf.c | Main function and check_specifier router |
| handlers.c | All conversion specifier handler functions |
| buffer.c | write_to_buffer — manages the 1024-byte local buffer |
| main.h | Header file with prototypes, includes, and BUF_SIZE macro |
| man_3_printf | Man page for the _printf function |

## Man Page

To view the man page:
man ./man_3_printf

## Authors

- Sara Alkhubaizi
- Reema Alshahrani

## Repository

GitHub: [holbertonschool-printf](https://github.com/holbertonschool-printf)
