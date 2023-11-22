#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * func_select - function selector
 * @format: string to be printed
 * @func_array: array to select the right format if needed
 * @ap: argument pointer
 * Return: Length of the string minus NULL character
 */
int func_select(const char *format, struct call func_array[], va_list ap)
{
	int i, j;
	int len = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; func_array[j].specifier != NULL; j++)
			{
				if (format[i + 1] == *func_array[j].specifier)
				{
					if (*func_array[j].specifier == 'c')
						len += func_array[j].func_call(ap);
					else if (*func_array[j].specifier == 's')
						len += func_array[j].func_call(ap);
					else if (*func_array[j].specifier == '%')
						len += func_array[j].func_call(ap);
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
	return (len);
}
