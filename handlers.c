#include <unistd.h>
#include <stdarg.h>

/**
 * handle_char - prints a character from va_list
 * @args: argument list
 *
 * Return: number of characters printed (always 1)
 */
int handle_char(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	write(1, &c, 1);
	return (1);
}


/**
 * handle_string - prints a string from va_list
 * @args: argument list
 *
 * Return: number of characters printed
 */
int handle_string(va_list args)
{
	char *s;
	int count = 0;

	s = va_arg(args, char *);
	if (!s)
		s = "(null)";
	while (*s)
	{
		write(1, s, 1);
		s++;
		count++;
	}
	return (count);
}
