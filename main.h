#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _putchar(char c);

int handle_char(va_list args);
int handle_string(va_list args);
int handle_int(int n);
int handle_int_helper(unsigned int num);
#endif
