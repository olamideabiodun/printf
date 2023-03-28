#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 *
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;

			if (!format[i])
				return (-1);

			if (format[i] == '%')
				count += _putchar('%');
			else if (format[i] == 'c')
				count += _putchar(va_arg(args, int));
			else if (format[i] == 's')
				count += _puts(va_arg(args, char *));
			else
				count += _putchar('%') + _putchar(format[i]);
		}
		else
			count += _putchar(format[i]);

		i++;
	}

	va_end(args);

	return (count);
}

