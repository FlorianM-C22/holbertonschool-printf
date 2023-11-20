#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * _printf - writes the output to stdout
 * @format: character string
 *
 * Return: the number of characters printed (excluding the NULL byte)
 * On error, -1 is returned, and errno is set appropriately.
 */
int _printf(const char *format, ...)
{
	int i;
	int len = strlen(format);

	if (format == NULL)
		return (-1);

	for (i = 0; i < len; i++)
	{

		if (format[i] == '%' && format[i + 1] == 's')
		{
			printf("Appel fonction string");
			_printstring(format[i]);
			i += 2;
		}

		if (format[i] == '%' && format[i + 1] == '%')
		{
			putchar('%');
			i += 2;
		}

	putchar(format[i]);
	}

	return (len);
}
