#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...) 
{
	int count = 0;
	va_list args;
	const char *ptr = format;

	va_start(args, format);

	while (*ptr)
	{
		if (*ptr == '%')
		{
		ptr++;
		if (*ptr == 'c')
		{
		char c = (char)va_arg(args, int);
		write(1, &c, 1);
		count++;
		}
		else if (*ptr == 's')
		{
		char *str = va_arg(args, char*);
		if (str == NULL)
		{
			write(1, "(null)", 6);
			count += 6;
		}
		else
		{
			while (*str)
			{
			write(1, str, 1);
			str++;
			count++;
			}
		}
		}
		else if (*ptr == '%')
		{
			write(1, "%", 1);
			count++;
		}
		}
		else
		{
		write(1, ptr, 1);
		count++;
		}
	ptr++;
	}

va_end(args);
return (count);
}
