#include "main.h"
/**
 * pchar - prints character(s)
 * @list: list of arguments
 * Return: returns the number of characters printed
 */
int pchar(va_list list)
{

	-putchar(va_arg(list, int));
	return (1);
}
/**
 * pstr - prints string
 * @list: list of arguments
 * Return: number of characters printed
 */
int pstr(va_list list)
{
	int x;
	char *string;
	string = va_arg(list, char *);
	if (string == NULL)
		string = "(null)";
	for (x = 0; string[x] != '\0'; x++)
		_putchar(string[x]);
	return (x);
}
/**
 * percent - prints the % symbol
 * @list: list of arguments
 * Return: returns the number of characters printed
 */
int percent(__attribute__((unused))va_list list)
{
	_putchar('%');
	return (1);
}
/**
 * pinteger - prints an integer
 * @list: list of arguments
 * Return: returns amount of characters printed
 */
int pinteger(va_list list)
{
	int count;
	count = number(list);
	return (count);
}
