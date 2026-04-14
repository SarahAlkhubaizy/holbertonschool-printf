#include "main.h"

/**
 * check_specifier - Checks and handles the specifier after %
 * @format: The specifier character
 * @args: The list of arguments
 *
 * Return: Number of characters printed
 */
int check_specifier(char format, va_list args)
{
	int count = 0;

	if (format == 'c')
		count = handle_char(args);
	else if (format == 's')
		count = handle_string(args);
	else if (format == 'd' || format == 'i')
		count = handle_int(args);
	else if (format == '%')
	{
		write(1, "%", 1);
		count = 1;
	}
	else
	{
		write(1, "%", 1);
		write(1, &format, 1);
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
	int i = 0, count = 0, res = 0;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(args, format);
	while (format && format[i])
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
			res = check_specifier(format[i], args);
			if (res == -1)
				return (-1);
			count += res;
		}
		i++;
	}
	va_end(args);
	return (count);
}
