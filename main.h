#ifndef __PROTECT__
#define __PROTECT__
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * struct call - selects the right function to associate with %
 * @specifier: which function to call
 * @func_call: name of the array
 */
typedef struct call
{
	char *specifier;
	int (*func_call)(va_list);
} call;

int _printf(const char *format, ...);
int _printchar(char c);
void (_printstring(char *s));
int _put_percent(char c);

#endif
