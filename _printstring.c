#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * _printstring - prints a char string to stdout
 * @ap: argument parameters
 * Return: Length of the string mins NULL character
 */
int (_printstring(va_list ap))
{
		/* initialize a string*/
		int s;
		char *str = va_arg(ap, char *);

		if (*str == '\0')
			return (-1);

		for (s = 0; str[s] != '\0'; s++)
			putchar(str[s]);

		return (s);
}
