#include "main.h"

/**
 * _printf - function that produces an output according to a format
 * @format: character string
 * @...: arguments
 * Return: the length of the string
 */

int _printf(const char *format, ...)
{
	int P_char;
	va_list arg;

	char n;

	P_char = 0;

	va_start(arg, format);

	while ((n = *format++) != '\0')
	{
		if (n != '%')
		{
			putchar(n);
			P_char++;
		}
		else
		{
			n = *format++;

			switch (n)
			{
			case 'c':
				{
				int val = va_arg(arg, int);
				putchar(val);
				P_char++;
				}
				break;
			case 's':
				{
				char *val = va_arg(arg, char*);
				P_char += printf("%s", val);
				}
				break;
			case '%':
				{
				putchar('%');
				P_char++;
				}
				break;
			default:
				{
				putchar('%');
				putchar('n');
				P_char += 2;
				}
			}
			break;
		}
	}
	va_end(arg);
	return (n);
}
