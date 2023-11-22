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
	call func_select[] = {
	{"c", _printchar},
	{"s", _printstring},
	{"%", _put_percent},
	{NULL, NULL}
};
	va_list ap;
	int i, j;
	int len = 0;

	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; func_select[j].specifier != NULL; j++)
			{
				if (format[i + 1] == *func_select[j].specifier)
				{
					if (*func_select[j].specifier == 'c')
						func_select[j].func_call(ap);
					else if (*func_select[j].specifier == 's')
						func_select[j].func_call(ap);
					else if (*func_select[j].specifier == '%')
						func_select[j].func_call(ap);
				break;
				}
			}
			i++;
		}
		else
		{
			putchar(format[i]);
			len++;
		}
	}
	va_end(ap);
	return (len);
}
