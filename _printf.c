#include "main.h"

/**/

int _printf(const char *format, ...)
{
	especificador_t especificador[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_%},
		{0, NULL}
	};

	va_list args;
	int i, count, j;
	char current;

	i = 0;
	count = 0;

	if (!format)
	{
		return (-1);
	}

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			current = format[i];
			j = 0;
			
			while (especificador[j].spec)
			{
				if (current == especificador[j].spec)
				{
					count += especificador[j].func(args);
					break;
				}
				j++;
			}

			if (!especificador[j].spec)
			{
				write(1, "%", 1);
				write(1, &current, 1);
				count += 2;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}

	va_end(args);
	return count;
}
