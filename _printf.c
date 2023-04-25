#include "main.h"

/**
 * _printf - functions that outputs a given format 
 * @format: character string
 * @...: arguments
 * Return: String character 
 */

int _printf(const char *format, ...)
{
	va_list args;
	int P_char;
	char n;

	va_start(args, format);

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
		int val = va_arg(args, int);
		putchar(val);
		P_char++;
		}
		break;
	case 's':
		{
		char *val = va_arg(args, char *);
		P_char += printf("%s", val);
		}
		break;
	case '%':
		{
		putchar('%');
		putchar(n);
		P_char += 2;
		}
		break;
	}
	}
	}
	va_end(args);
	return (P_char);
}
