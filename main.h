#ifndef MAIN_H
#define MAIN_H
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct specifier {
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

#endif
