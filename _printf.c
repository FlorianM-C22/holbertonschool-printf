#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

typedef struct func_selec
{
	char *specifier;
	int (*func_call)(va_list);
} call;

int _printchar(va_list c)
{
	int c;

	_putchar(va_arg(c, int));
}

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

	va_list ap;

	va_start(ap, format);

	call func_select[] = {
		{"c", _printchar},
		/*{"s", _printstring},*/
		/*{"%", _put_percent},*/
		{NULL, NULL}
	};

	for (i = 0; i < len; i++)
	{

		if (format[i] == '%')
		{
			if (format[i + 1] == *func_select[0].specifier)
				func_select[0].func_call(ap);
		}

		/*if (format[i] == '%' && format[i + 1] == '%')
		{
			putchar('%');
			i += 2;
		}
		*/

	va_end(ap);

	putchar(format[i]);

	}

	return (len);
}
