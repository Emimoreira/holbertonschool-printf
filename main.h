#ifndef MAIN_H
#define MAIN_H
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct specifier - asocia especificadores de formato con funciones
 * @spec: El especificador de formato
 * @func: Un puntero a una función que maneja el tipo de formato correspondien
 */

typedef struct specifier
{
	char spec;
	int (*func)(va_list);
} specifier_t;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list val);
int print_str(va_list val);
int _strlen(char *s);
int _strlenc(const char *s);
int print_porcentaje(va_list args);
int print_integer(va_list args);
int print_decimal(va_list args);

#endif
