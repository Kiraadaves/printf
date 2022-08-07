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
