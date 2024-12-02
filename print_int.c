#include "main.h"

/**
 * print_integer - Imprime un número entero
 * @args: El argumento a imprimir
 * Return: Número de caracteres impresos
 */
int print_integer(va_list args)
{
	int n = va_arg(args, int);
	int count = 0, num, last_digit, digit, exp = 1;

	last_digit = n % 10;
	num = n / 10;

	if (n < 0)

	{
		_putchar('-');
		num = -num;
		n = -n;
		last_digit = -last_digit;
		count++;
	}

	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp *= 10;
			num /= 10;
		}

		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num -= digit * exp;
			exp /= 10;
			count++;
		}
	}

	_putchar(last_digit + '0');
	count++;

	return (count);
}

/**
 * print_decimal - Imprime un número decimal
 * @args: El argumento a imprimir
 * Return: Número de caracteres impresos
 */

int print_decimal(va_list args)
{
	int n = va_arg(args, int);
	int count = 0, num, last_digit, digit, exp = 1;

	last_digit = n % 10;
	num = n / 10;

	if (n < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last_digit = -last_digit;
		count++;
	}

	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp *= 10;
			num /= 10;
		}

		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num -= digit * exp;
			exp /= 10;
			count++;
		}
	}

	_putchar(last_digit + '0');
	count++;

	return (count);
}
