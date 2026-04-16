#  _printf

A custom implementation of the C standard library function printf,  
written in C as part of the Holberton School curriculum.

---

##  Description

_printf produces output according to a format string and writes  
the result to the standard output (`stdout`).  
It supports a subset of the standard printf conversion specifiers.

---

##  How It Works

- Reads the format string character by character  
- When encountering %, it calls the appropriate handler function  
- Otherwise, it prints the character directly to stdout  

---

##  Project Files

| File | Description |
|------|-------------|
| _printf.c | Main function and specifier dispatcher |
| handlers.c | Handles each conversion specifier |
| main.h | Header file with all function prototypes |
| man_3_printf | Manual page for _printf |

---

##  Supported Conversion Specifiers

| Specifier | Description |
|-----------|-------------|
| %c | Prints a single character |
| %s | Prints a string |
| %d | Prints a decimal integer |
| %i | Prints an integer |
| %% | Prints a literal % character |

---

##  Examples

```c
_printf("Hello, World!\n");
_printf("Number: %d\n", 42);
_printf("Char: %c\n", 'A');
_printf("String: %s\n", "Holberton");
_printf("Negative: %d\n", -762534);
_printf("Percent: %%\n");
