#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * _put_percent - prints the modulo sign
 * @ap: argument parameters
 * Return: number of characters printed
 */
int _put_percent(va_list ap)
{
	(void)ap; /*Ignores the parameter list*/

	putchar('%');/*Prints "%"*/

	return (1);/*Return the number of characters printed*/
}
