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
	/*Extract the integer from the argument list*/
	int value = va_arg(ap, int);
	/*Variables to keep track of the count and the digits of the number*/
	int count = 0;
	int digits[12];/*An integer will never contain more than 12 digits*/
	int index = 0;
	int i;

	if (value < 0) /*Handling negative values*/
	{
		putchar('-');
		value = -value; /*Converts number to its absolute value*/
		count++;
	}
	/*Extracting the digits to store them in the array*/
	do {
		digits[index++] = value % 10;
		value /= 10;
	} while (value > 0);

	/*Printing in reverse order to get the correct output*/
	for (i = index - 1; i >= 0; i--)
	{
		putchar('0' + digits[i]);
		count++;
	}
	/*Return the total count of characters printed*/
	return (count);
}
