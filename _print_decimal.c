#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 * _print_decimal - writes the decimal values to stdout
 * @ap: Argument pointer
 * Return: len
 */
int (_print_decimal(va_list ap))
{
	int value = va_arg(ap, int);
	int count = 0;
	int digits[12];
	int index = 0;
	int i;

	if (value < 0)
	{
		putchar('-');
		value = -value;
		count++;
	}

	do {
		digits[index++] = value % 10;
		value /= 10;
	} while (value > 0);

	for (i = index - 1; i >= 0; i--)
	{
		putchar('0' + digits[i]);
		count++;
	}
	return (count);
}
