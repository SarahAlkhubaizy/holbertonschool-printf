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
