#include "main.h"
/**
 * pchar - prints character(s)
 * @list: list of arguments
 * Return: returns the number of characters printed
 */
int pchar(va_list list)
{

	_putchar(va_arg(list, int));
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
/**
 * unsigned_int - prints unsigned integers
 * @list: list of all arguments
 * Return: a count of numbers
 */
int unsigned_int(va_list list)
{
	unsigned int x;

	x = va_arg(list, unsigned int);

	if (x == 0)
		return (unsigned_number(x));
	if (x < 1)
		return (-1);
	return (unsigned_number(x));
}

/**
 * print_unsigned - prints an unsigned integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_unsigned(va_list l)
{
	unsigned int u = va_arg(l, unsigned int);
	char *str = convert(u, 10, 0);
	return (_puts(str));
}

/**
 * print_bigS - Non printable characters
 * (0 < ASCII value < 32 or >= 127) are
 * printed this way: \x, followed by the ASCII code
 * value in hexadecimal (upper case - always 2 characters)
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of chars printed
 */

int print_bigS(va_list l)
{
	int i, count = 0;
	char *res;
	char *s = va_arg(l, char *);
	if (!s)
		return (_puts("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			_puts("\\x");
			count += 2;
			res = convert(s[i], 16, 0);
			if (!res[1])
				count += _putchar('0');
			count += _puts(res);
		}
		else
			count += _putchar(s[i]);
	}
	return (count);
}

/**
 * print_rev - prints a string in reverse
 * @l: argument from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: length of the printed string
 */

int print_rev(va_list l)
{
	int i = 0, j;
	char *s = va_arg(l, char *);
	if (!s)
		s = "(null)";

	while (s[i])
		i++;

	for (j = i - 1; j >= 0; j--)
		_putchar(s[j]);

	return (i);
}

/**
 * print_rot13 - prints a string using rot13
 * @l: list of arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: length of the printed string
 */

int print_rot13(va_list l)
{
	int i, j;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(l, char *);
	for (j = 0; s[j]; j++)
	{
		if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
			_putchar(s[j]);
		else
		{
			for (i = 0; i <= 52; i++)
			{
				if (s[j] == rot13[i])
					_putchar(ROT13[i]);
			}
		}
	}

	return (j);
}

/**
 * print_address - prints address of input in hexa format
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of chars printed
 */

int print_address(va_list l)
{
	char *str;
	unsigned long int p = va_arg(l, unsigned long int);

	register int count = 0;
	if (!p)
		return (_puts("(nil)"));
	str = convert(p, 16, 1);
	count += _puts("0x");
	count += _puts(str);
	return (count);
}
