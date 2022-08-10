#include "main.h"

/**
 * _printf -> prints anything on the atdout
 * @format: string literal for formating text input
 * Return: returns integer value of all characters printed
 */

int _printf(const char *format, ...)
{
int printed;
toPrint func[] = {
	{"c", pchar},
	{"s", pstr},
	{"%", percent},
	{"d", pinteger},
	{"i", pinteger},
	{"b", print_binary},
	{"x", print_hex},
	{"X", print_hex_big},
	{"o", print_octal},
	{"u", print_unsigned},
	{"R", print_rot13},
	{"r", print_rev},
	{"S", print_bigS},
	{"p", print_address},
	{NULL, NULL}
};
va_list args;

if (format == NULL)
	return (-1);

va_start(args, format);
printed = parse(format, func, args);
va_end(args);
return (printed);
}
