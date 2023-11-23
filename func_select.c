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
			int specifier_found = 0;

			for (j = 0; func_array[j].specifier != NULL; j++)
			{
				if (format[i + 1] == *func_array[j].specifier)
				{
					/* Handle known specifiers here */
					len += func_array[j].func_call(ap);
					specifier_found = 1;
					break;
				}
			}

			if (!specifier_found)
			{
				putchar('%');
				putchar(format[i + 1]);
				len += 2;
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
