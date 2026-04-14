#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int handle_char(va_list args);
int handle_string(va_list args);
int handle_int(int n);
int _putchar(char c);

#endif
