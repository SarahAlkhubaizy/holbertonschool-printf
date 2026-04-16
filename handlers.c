#include <unistd.h>
#include <stdarg.h>

int handle_char(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

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

int handle_int(va_list args)
{
	int n;
	int count = 0;
	int divisor;
	int temp;
	char digit;

	n = va_arg(args, int);

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		if (n == -2147483648)
		{
			write(1, "2147483648", 10);
			return (count + 10);
		}
		n = -n;
	}

	divisor = 1;
	temp = n;
	while (temp >= 10)
	{
		divisor *= 10;
		temp /= 10;
	}

	while (divisor >= 1)
	{
		digit = '0' + (n / divisor);
		write(1, &digit, 1);
		count++;
		n %= divisor;
		divisor /= 10;
	}

	return (count);
}

/**
 * handle_binary - prints unsigned int in binary
 * @args: argument list
 *
 * Return: number of characters printed
 */
int handle_binary(va_list args)
{
	unsigned int n;
	unsigned int divisor;
	unsigned int temp;
	int count;
	char digit;

	count = 0;
	n = va_arg(args, unsigned int);
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	divisor = 1;
	temp = n;
	while (temp >= 2)
	{
		divisor *= 2;
		temp /= 2;
	}
	while (divisor >= 1)
	{
		digit = '0' + (n / divisor);
		write(1, &digit, 1);
		count++;
		n %= divisor;
		divisor /= 2;
	}
	return (count);
}

/**
 * handle_unsigned - prints unsigned integer
 * @args: argument list
 *
 * Return: number of characters printed
 */
int handle_unsigned(va_list args)
{
	unsigned int n;
	unsigned int divisor;
	unsigned int temp;
	int count;
	char digit;

	count = 0;
	n = va_arg(args, unsigned int);
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	divisor = 1;
	temp = n;
	while (temp >= 10)
	{
		divisor *= 10;
		temp /= 10;
	}
	while (divisor >= 1)
	{
		digit = '0' + (n / divisor);
		write(1, &digit, 1);
		count++;
		n %= divisor;
		divisor /= 10;
	}
	return (count);
}

/**
 * handle_octal - prints unsigned integer in octal
 * @args: argument list
 *
 * Return: number of characters printed
 */
int handle_octal(va_list args)
{
	unsigned int n;
	unsigned int divisor;
	unsigned int temp;
	int count;
	char digit;

	count = 0;
	n = va_arg(args, unsigned int);
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	divisor = 1;
	temp = n;
	while (temp >= 8)
	{
		divisor *= 8;
		temp /= 8;
	}
	while (divisor >= 1)
	{
		digit = '0' + (n / divisor);
		write(1, &digit, 1);
		count++;
		n %= divisor;
		divisor /= 8;
	}
	return (count);
}

/**
 * handle_hex - prints unsigned integer in hexadecimal
 * @args: argument list
 * @uppercase: 1 for uppercase, 0 for lowercase
 *
 * Return: number of characters printed
 */
int handle_hex(va_list args, int uppercase)
{
	unsigned int n;
	unsigned int divisor;
	unsigned int temp;
	int count;
	char digit;
	char *hex;

	count = 0;
	hex = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	n = va_arg(args, unsigned int);
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	divisor = 1;
	temp = n;
	while (temp >= 16)
	{
		divisor *= 16;
		temp /= 16;
	}
	while (divisor >= 1)
	{
		digit = hex[n / divisor];
		write(1, &digit, 1);
		count++;
		n %= divisor;
		divisor /= 16;
	}
	return (count);
}
