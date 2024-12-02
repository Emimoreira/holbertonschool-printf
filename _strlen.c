#include "main.h"

/**
 * _strlen - cuenta longitud de string
 * @s: apunta al string
 * Return: longitud del string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strlenc - lo mismo pero ampliado para los const
 * @s: puntero a string
 * Return: longitud del string
 */

int _strlenc(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
