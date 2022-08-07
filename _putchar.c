#include "main.h"

/**
 * _putchar - prints a character to the screen
 * @c: character to be printed
 * Return: returns 1 on success and -1 on error
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
