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
	/*Array of function pointers and corresponding format specifiers*/
	call func_array[] = {
	{"c", _printchar},
	{"s", _printstring},
	{"%", _put_percent},
	{"d", _print_decimal},
	{"i", _print_decimal},
	{NULL, NULL}
};
	va_list ap;

	int i = 0; /*Index value*/
	int len = 0;/*Tracking length*/

	va_start(ap, format);

	/*Checking for empty string*/
	if (*format == '\0')
		return (-1);

	/*Checks for the special case of "%" and a space*/
	if (format[i] == '%' && format[i + 1] == ' ' && format[i + 2] == '\0')
	{
		putchar('%');
		putchar(' ');
	}
	/*Calls the function selector*/
	len += func_select(format, func_array, ap);

	va_end(ap);
	/*Returns the number of characters printed excluding NULL char*/
	return (len);
}
