#include "main.h"

/**
 * _printf - Imita el comportamiento de printf
 * @format: Cadena con el formato de impresión
 * Return: Número de caracteres impresos o -1 si hay un error
 */

int _printf(const char * const format, ...)
{
	especificador p[] = {
		{"%s", print_str}, {"%c", print_char},
		{"%%", print_porcentaje},
	};

	va_list args;
	int i = 0, j, length = 0;
	int size = 2;

	if (format == NULL)
	{
		return (-1);
	}
	
	va_start(args, format);
	
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			for (j = 0; j < size; j++)
			{
				if (p[j].ph[0] == format[i] && p[j].ph[1] == format[i + 1])
				{
					length += p[j].function(args);
					i += 2;
					break;
				}
			}
			if (j == size)
			{
				_putchar(format[i]);
				length++;
				i++;
			}
		}
		else
		{
			_putchar(format[i]);
			length++;
			i++;
		}
	}
	va_end(args);
	return (length);
}
