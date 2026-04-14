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
#include "main.h"

/**
 * handle_int - prints an integer using recursion
 * @n: integer to be printed
 *
 * Return: the total number of characters printed
 */

#include "main.h"

/**
 * handle_int - prints an integer using recursion
 * @n: integer to be printed
 *
 * Return: the total number of characters printed
 */

int handle_int(int n)
{
	int count = 0;
	unsigned int num;

	/* 1. Handle negative numbers */
	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	/* 2. Recursion to print digits in the correct order */
	if (num / 10)
	{
		/* We cast to handle the next recursive call correctly */
		count += handle_int_helper(num / 10);
	}

	/* 3. Print the last digit by converting it to ASCII */
	count += _putchar((num % 10) + '0');

	return (count);
}
