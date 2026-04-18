#include "main.h"

/**
 * handle_char - handles character printing
 */
int handle_char(va_list args, char *buffer, int *index)
{
	char c = (char)va_arg(args, int);

	return (write_to_buffer(c, buffer, index));
}

/**
 * handle_string - handles string printing
 */
int handle_string(va_list args, char *buffer, int *index)
{
	char *s = va_arg(args, char *);
	int count = 0;

	if (!s)
		s = "(null)";

	while (*s)
	{
		count += write_to_buffer(*s, buffer, index);
		s++;
	}
	return (count);
}

/**
 * handle_int - handles integer printing
 */
int handle_int(va_list args, char *buffer, int *index)
{
	int n = va_arg(args, int);
	int count = 0, divisor = 1;
	unsigned int num;

	if (n < 0)
	{
		count += write_to_buffer('-', buffer, index);
		num = -n;
	}
	else
		num = n;

	while (num / divisor >= 10)
		divisor *= 10;

	while (divisor >= 1)
	{
		count += write_to_buffer('0' + (num / divisor), buffer, index);
		num %= divisor;
		divisor /= 10;
	}
	return (count);
}

/**
 * handle_binary - prints unsigned int in binary
 */
int handle_binary(va_list args, char *buffer, int *index)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int divisor = 1;
	int count = 0;

	if (n == 0)
		return (write_to_buffer('0', buffer, index));

	while (n / divisor >= 2)
		divisor *= 2;

	while (divisor >= 1)
	{
		count += write_to_buffer('0' + (n / divisor), buffer, index);
		n %= divisor;
		divisor /= 2;
	}
	return (count);
}

/**
 * handle_unsigned - prints unsigned integer
 */
int handle_unsigned(va_list args, char *buffer, int *index)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int divisor = 1;
	int count = 0;

	if (n == 0)
		return (write_to_buffer('0', buffer, index));

	while (n / divisor >= 10)
		divisor *= 10;

	while (divisor >= 1)
	{
		count += write_to_buffer('0' + (n / divisor), buffer, index);
		n %= divisor;
		divisor /= 10;
	}
	return (count);
}

/**
 * handle_octal - prints unsigned integer in octal
 */
int handle_octal(va_list args, char *buffer, int *index)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int divisor = 1;
	int count = 0;

	if (n == 0)
		return (write_to_buffer('0', buffer, index));

	while (n / divisor >= 8)
		divisor *= 8;

	while (divisor >= 1)
	{
		count += write_to_buffer('0' + (n / divisor), buffer, index);
		n %= divisor;
		divisor /= 8;
	}
	return (count);
}

/**
 * handle_hex - prints unsigned integer in hexadecimal
 */
int handle_hex(va_list args, int uppercase, char *buffer, int *index)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int divisor = 1;
	int count = 0;
	char *hex = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (n == 0)
		return (write_to_buffer('0', buffer, index));

	while (n / divisor >= 16)
		divisor *= 16;

	while (divisor >= 1)
	{
		count += write_to_buffer(hex[n / divisor], buffer, index);
		n %= divisor;
		divisor /= 16;
	}
	return (count);
}
