#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

int (_printstring(va_list ap))
{
		int s;
		char *str = va_arg(ap, char *);

		for (s = 0; str[s] != '\0'; s++)
			putchar(str[s]);

		return (s);
}
