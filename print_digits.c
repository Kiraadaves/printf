#include "main.h"
/**
 * number - prints a number
 * @args: argument
 * Return: number of arguments printed
 */
int number(va_list args)
{
	int n;
	int div;
	int total = 0;
	unsigned int x;

	n = va_arg(args, int);
	div = 1;

	if (n < 0)
	{
		total += _putchar('-');
		x = n * -1;
	}
	else
		x = n;
	for (; x / div > 9;)
		div *= 10;
	for (; div != 0;)
	{
		total += _putchar(x / div + '0');
		x %= div;
		div /= 10;
	}
	return (total);
}
/**
 * unsigned_number - prints an unsigned number
 * @x: unsigned int to be printed
 * Return: returns integer value
 */
int unsigned_number(unsigned int x)
{
	int div = 1;
	int add = 0;
	unsigned int i;

	i = x;

	for (; i / div > 9;)
		div *= 10;
	for (; div != 0;)
	{
		add += _putchar('0' + i / div);
		i %= div;
		div /= 10;
	}
	return (add);
}
