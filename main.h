#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct forPrintf -> structure contrary functions
 *
 * @operation: the operator
 * @f: function
 */

struct forPrintf
{
	char *operation;
	int (*f)(va_list);
};
typedef struct forPrintf toPrint;

int _printf(const char *format, ...);
int _putchar(char);
int pchar(va_list);
int pstr(va_list);
int percent(va_list);
int pinteger(va_list);
int number(va_list);
int parse(const char *format, toPrint func[], va_list args);
int unsigned_int(va_list);
int unsigned_number(unsigned int);

#endif
