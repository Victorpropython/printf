#include "main.h"

/**
 * handle_width - Calculates the width for printing
 * @modifier: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @args: list of arguments.
 *
 * Return: width.
 */
int handle_width(va_list args, const char *modifier, char *i)
{
	int curr_m = 0;

	while ((*modifier >= '0' && *modifier <= '9') ||
		(*modifier == '*'))
	{
		(i)++;

		if (*modifier == '*')
		{
			curr_m = va_arg(args, int);
			if (curr_m <= 0)
				return (0);
			return (curr_m);

		}
		curr_m *= 10;
		curr_m += (*modifier - '0');
		modifier++;
	}
	return (curr_m);
}
