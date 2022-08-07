#include "main.h"

/**
 * parse - recieves main string and other parameters
 * @format: string to print
 * @func: list of functions
 * @args: all arguments passed
 *
 * Return: total count of what was printed
 */

int parse(const char *format, toPrint func[], va_list args)
{
	int i, j, x, printed;

	printed = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; func[j].operation != NULL; j++)
			{
				if (format[i + 1] == func[j].operation[0])
				{
					x = func[j].f(args);
					if (x == -1)
						return (-1);
					printed += x;
					break;
				}
			}
			if (func[j].operation == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					printed = printed + 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			printed++;
		}
	}
	return (printed);
}
