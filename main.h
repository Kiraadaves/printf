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
int print_binary(va_list l);
int _puts(char *str);
char *convert(unsigned long int num, int base, int lowercase);
int print_hex(va_list l);
int print_hex_big(va_list l);
int print_octal(va_list l);
int print_unsigned(va_list l);
int print_rot13(va_list l);
int print_rev(va_list l);
int print_bigS(va_list l);
int print_address(va_list l);

#endif
