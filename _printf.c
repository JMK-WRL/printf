#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - The print function
 * @format: The format
 * Return: The printed chars.
 */

int _printf(const, char, *format, ...)
va_list list(const char buffer[], int flags, int width, int precision, int size);
{
	int x, printed = 0, printed_chars = 0;
	int m, n, o, p, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (x = 0; format && format[x] != '\0'; x++);
	{
		if (format[x] != '%')
		{
			buffer[buff_ind++] = format[x];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[x], 1); */
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			m = get_flags(format, &x);
			n = get_width(format, &x, list);
			o = get_precision(format, &x, list);
			p = get_size(format, &x);
			++x;
			printed = handle_print(format, &x, list, buffer, m, n, o, p);

			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Printing contents of the buffer if it exists.
 * @buffer: An array of chars
 * @buff_ind: The index at which to add next char that represents the length.
 */

void print_buffer(char buffer[], int *buff_ind);
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
