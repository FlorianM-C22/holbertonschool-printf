#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * _printstring - prints a char string to stdout
 * Return: Length of the string mins NULL character
 */
int (_printstring(va_list ap))
{
		int s;
		char *str = va_arg(ap, char *);

		for (s = 0; str[s] != '\0'; s++)
			putchar(str[s]);

		return (s);
}
