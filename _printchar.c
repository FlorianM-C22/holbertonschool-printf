#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printchar - writes the character c to stdout calling _putchar
 *@ap: argument pointer
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _printchar(va_list ap)
{
	/*Extract the character argument from the list*/
	char charac = (char)va_arg(ap, int);
	/*Calling putchar to write the character*/
	putchar(charac);
	/*Return the number of characters printed*/
	return (1);
}
