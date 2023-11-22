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
		int s, count = 0;
		char *str = va_arg(ap, char *);

		for (s = 0; str[s] != '\0'; s++)
			count += putchar(str[s]);

		return (count);
}
