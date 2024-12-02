#include <stdarg.h>
#include "main.h"

/**
 * _printf - Imita el comportamiento de printf
 * @format: Cadena con el formato de impresió
 * Return: Númro de caracteres impresos o -1 si hay un error
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i = 0, j, found;

	specifier_t specifiers[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_porcentaje},
	};

	int num_specifiers = 3;

	va_start(args, format);
	
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			found = 0;
			for (j = 0; j < num_specifiers; j++)
			{
				if (format[i] == specifiers[j].spec)
				{
					count += specifiers[j].func(args);
					found = 1;
					break;
				}
			}
			
			if (!found)
			{
				_putchar('%');
				_putchar(format[i]);
				count += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}

	va_end(args);
	return count;
}
