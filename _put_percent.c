#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * _put_percent - prints the modulo sign
 * Return: number of characters printed
 */
int _put_percent(va_list ap)
{
	(void)ap;

	putchar('%');

	return (1);
}
