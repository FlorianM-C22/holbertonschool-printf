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
	/*Initialize variables for iteration and tracking length*/
	int i, j;
	int len = 0;
	/*Iterate through the format string*/
	for (i = 0; format[i] != '\0'; i++)
	{
		/*Checks for the '%' indicating a format specifier*/
		if (format[i] == '%')
		{
			int specifier_found = 0;

			/*Iterating through func_array to find matching specifier*/
			for (j = 0; func_array[j].specifier != NULL; j++)
			{
				if (format[i + 1] == *func_array[j].specifier)
				{
					/*Calling the right function for the found specifier*/
					len += func_array[j].func_call(ap);
					specifier_found = 1;
					break;
				}
			}
			/*If specifier not found, print '%' followed by next character*/
			if (!specifier_found)
			{
				putchar('%');
				putchar(format[i + 1]);
				len += 2;
			}
			/*Skipping next char since it's been processed*/
			i++;
		}
		else
		{
			putchar(format[i]);
			len++;
		}
	}
	/*Return the total length of the string except NULL char*/
	return (len);
}

