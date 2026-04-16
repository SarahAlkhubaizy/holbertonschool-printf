#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * check_specifier - handles format specifier
 * @c: the specifier character
 * @args: argument list
 *
 * Return: number of characters printed
 */
int check_specifier(char c, va_list args)
{
	int count;

	count = 0;
	if (c == 'c')
		count = handle_char(args);
	else if (c == 's')
		count = handle_string(args);
	else if (c == 'd' || c == 'i')
		count = handle_int(args);
	else if (c == 'b')
                count = handle_binary(args);
	else if (c == '%')
	{
		write(1, "%", 1);
		count = 1;
	}
	else
	{
		write(1, "%", 1);
		write(1, &c, 1);
		count = 2;
	}
	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: character string with directives
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i;
	int count;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		else
		{
			i++;
			if (!format[i])
			{
				va_end(args);
				return (-1);
			}
			count += check_specifier(format[i], args);
		}
		i++;
	}
	va_end(args);
	return (count);
}
