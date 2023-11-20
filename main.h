#ifndef __protect__
#define __protect__


typedef struct func_selec
{
	const char *specifier;
	int (*func_call)(char);
} call;

int _printf(const char *format, ...);
int _printchar(char c);
void (_printstring(char *s));
int _put_percent(char c);

#endif
