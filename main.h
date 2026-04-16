#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
int _printf(const char *format, ...);
int handle_char(va_list args);
int handle_string(va_list args);
int handle_int(va_list args);
int handle_binary(va_list args);
int handle_unsigned(va_list args);
int handle_octal(va_list args);
int handle_hex(va_list args, int uppercase);
#endif
