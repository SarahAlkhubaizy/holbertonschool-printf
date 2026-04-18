#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define BUF_SIZE 1024
int write_to_buffer(char c, char *buffer, int *index);
int _printf(const char *format, ...);
int check_specifier(char c, va_list args, char *buffer, int *index);
int handle_char(va_list args, char *buffer, int *index);
int handle_string(va_list args, char *buffer, int *index);
int handle_int(va_list args, char *buffer, int *index);
int handle_binary(va_list args, char *buffer, int *index);
int handle_unsigned(va_list args, char *buffer, int *index);
int handle_octal(va_list args, char *buffer, int *index);
int handle_hex(va_list args, int uppercase, char *buffer, int *index);
int handle_S(va_list args, char *buffer, int *index);
#endif
