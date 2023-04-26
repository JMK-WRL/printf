#include "main.h"

/**
 * _printf - function that outputs a format
 * @format: string character
 * @...: arguments
 * Return: format string
 */

int _printf(const char *format, ...)
{
    va_list args;
    int written;
    char ch;

    va_start(args, format);

    while ((ch = *format++) != '\0')
    {
        if (ch != '%')
        {
            putchar(ch);
            written++;
        }
        else
        {
            ch = *format++;

            
	    switch (ch)
            {
            case 'c':
                {
                    int value = va_arg(args, int);
                    putchar(value);
                    written++;
                }
                break;
            case 's':
                {
                    char *value = va_arg(args, char *);
		    written += printf("%s", value);
		}
                break;
            case '%':
                {
                    putchar('%');
  		    written++;
                }
                break;
            default:
                {
                    putchar('%');
                    putchar(ch);
                    written += 2;
                }
                break;
            }
        }
    }

    va_end(args);

    return written; 
}

#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list arg;
	int x = 0;

	va_start(arg, format);

	while (*format != '\0')
	{
		if(*format == '%')
		{
			format++;

			if(*format == 'd' || *format == 'i')
			{
				int value = va_arg(arg, int);
				printf("%d", value);
				done++;
			}
		}
		else
		{
			putchar(*format);
			done++;
		}
		format++;
	}

	va_end(arg);

	return(arg);
}

