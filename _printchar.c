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
	char charac = (char)va_arg(ap, int);

	putchar(charac);
	return (1);
}
