#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - prints a char string to stdout
 * @format: The character to print
 * Return: Length of the string minus NULL character
 */
int _printf(const char *format, ...)
{
	call func_select[] = {
	{"c", _printchar},
	{"s", _printstring},
	/*{"%", _put_percent},*/
	{NULL, NULL}
};

	int i, j;
	int len = 0;

	va_list ap;

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
					/*else if (*func_select[j].specifier == '%')
						func_select[j].func_call(ap);*/

				break;
				}
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
	}

	va_end(ap);

	return (len);
}

int main(void)
{
	int len;
	int len2;
	char c = 'a';

	len = _printf("Let's try to printf a simple sentence.\n",);
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);

	return (0);
}
