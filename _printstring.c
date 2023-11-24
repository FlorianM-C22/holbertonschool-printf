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
	/*Extract string argument from the list*/
	char *str = va_arg(ap, char *);
	int i;/*Index value*/

		/*Checks if the string is NULL and print (null) if so*/
		if (str == NULL)
		{
			write(1, "(null)", 6);
			return (6);
		}
		/*Iterate through the string and print each character*/
		for (i = 0; str[i] != '\0'; i++)
			putchar(str[i]);

		/*Return the length of the string excluding NULL char*/
		return (i);
}
