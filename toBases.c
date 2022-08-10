#include "main.h"
/**
 * print_binary - prints a number in base 2
 * @l: va_list arguments from printf
 * Description: function calls toPrint(0
 * which in turn  converts input
 * Return: number of chars printed
 */
int print_binary(va_list l)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 2, 0);

	return (_puts(str));
}

/**
 * print_hex - prints in hexadecimal base
 * in lowercase
 * @l: va_list arguments from _printf
 * Description: the function calls convert() which
 * converts input to correct base and returns
 * a string
 * Return: number of char printed
 */
int print_hex(va_list l)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 16, 1);
	int count = 0;

	count += _puts(str);
	return (count);
}

/**
 * print_hex_big - prints a number in hexadecimal base
 * in uppercase
 * @l: va_list argument
 * Description: the function calls convert
 * Return: the number of chars printed
 */
int print_hex_big(va_list l)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 16, 0);
	int count = 0;

	count += _puts(str);
	return (count);
}

/**
 * print_octal - prints number in base 8
 * @l: va_list argument
 * Description: function calls convert()
 * Return: number of printer chars
 */
int print_octal(va_list l)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 8, 0);
	int count = 0;

	count += _puts(str);
	return (count);
}

