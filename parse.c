#include <stdio.h>
#include "main.h"

/**
 *
 *
 */

int parse(const char *format, toPrint func[], va_list args)
{
	int i, j, x, printed;
	printed = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; func[j].sym != NULL; j++)
			{
				if (format[i + 1] == func[i].sym[0])
				{
					x = func[j].f[args];
					if (x == -1)
						return (-1);
					printed += x;
					break;
				}
			}
			if (func[j].sym ==NULL && format[i + 1] != ' ')
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
