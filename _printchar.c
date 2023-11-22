#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printchar - writes the character c to stdout calling _putchar
 *@c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _printchar(va_list ap)
{
	return (putchar(va_arg(ap, int)));
}
