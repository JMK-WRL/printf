#include "main.h"
#include <stdio.h>

/**
 * _printf - The custom printing function
 * @format: The format string
 *
 * Return: The number of chracters that are printed.
 */

int _print(const char *format, ...)
{
	va_list args;
	int x, count = 0;
	char z, *o;

	va_start(args, format);

	for (x = 0; format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			putchar(format[x]);
			count++;
		}
		else
		{
			switch (format[++x])
			{
				case 'c':
					c = va_arg(args, int);
					putchar(c);
					count++;
					break;
				case 's':
					s = va_arg(args, char *);
					while (*s)
					{
						putchar(*s++);
						count++;
					}
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(format[x]);
					count += 2;
					break;
			}
		}
	}

	va_end(args);

	return (count);
}
