#include "main.h"

/**
 * check_specifier - routes the format specifier to the correct handler
 * @c: the specifier character (e.g., 'd', 's', 'c')
 * @args: the list of variable arguments
 * @buffer: local buffer of 1024 chars
 * @index: current position in the buffer
 *
 * Return: number of characters handled
 */
int check_specifier(char c, va_list args, char *buffer, int *index)
{
	int count = 0;

	if (c == 'c')
		count = handle_char(args, buffer, index);
	else if (c == 's')
		count = handle_string(args, buffer, index);
	else if (c == 'd' || c == 'i')
		count = handle_int(args, buffer, index);
	else if (c == 'b')
		count = handle_binary(args, buffer, index);
	else if (c == 'u')
		count = handle_unsigned(args, buffer, index);
	else if (c == 'o')
		count = handle_octal(args, buffer, index);
	else if (c == 'x')
		count = handle_hex(args, 0, buffer, index);
	else if (c == 'X')
		count = handle_hex(args, 1, buffer, index);
	else if (c == '%')
		count = write_to_buffer('%', buffer, index);
	else
	{
		/* If specifier is unknown, print the '%' and the character */
		write_to_buffer('%', buffer, index);
		write_to_buffer(c, buffer, index);
		count = 2;
	}
	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: character string with directives
 *
 * Return: total number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	char buffer[BUF_SIZE];
	int i = 0, count = 0, buf_idx = 0;

	if (!format)
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			/* Add normal characters to buffer */
			count += write_to_buffer(format[i], buffer, &buf_idx);
		}
		else
		{
			i++; /* Move to the character after '%' */
			if (!format[i])
			{
				va_end(args);
				return (-1);
			}
			/* Pass everything to the specifier checker */
			count += check_specifier(format[i], args, buffer, &buf_idx);
		}
		i++;
	}

	/* IMPORTANT: Print any remaining characters in the buffer before exiting */
	if (buf_idx > 0)
		write(1, buffer, buf_idx);

	va_end(args);
	return (count);
}
