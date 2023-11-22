#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - prints a char string to stdout
 * @format: The string to print
 * Return: Length of the string minus NULL character
 */
int _printf(const char *format, ...)
{
	call func_array[] = {
	{"c", _printchar},
	{"s", _printstring},
	{"%", _put_percent},
	{NULL, NULL}
};
	va_list ap;
	int i = 0;
	int len = 0;

	va_start(ap, format);

	if (format[i] == '\0' || (format[i] == '%' && format[i + 1] == '\0'))
		return (-1);

	if (format[i] == '%' && format[i + 1] == ' ' && format[i + 2] == '\0')
	{
		putchar('%');
		putchar(' ');
	}

	len += func_select(format, func_array, ap);

	va_end(ap);
	return (len - 1);
}
