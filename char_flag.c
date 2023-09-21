#include "main.h"

/**
 * handle_flags - Calculates active flags
 * @flag: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
unsigned char handle_flags(const char *flag, char *m)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int u, curr_m;
	unsigned char ren = 0;
	flag_v flags[] = {
		{'-', NEG},
		{'+', PLUS},
		{'0', ZERO},
		{'#', HASH},
		{' ', SPACE},
		{0, 0}
		};

	for (curr_m = *m + 1; flag[curr_m] != '\0'; curr_m++)
	{
		for (u = 0; flags[u].flag != '\0'; u++)
			if (flag[curr_m] == flags[u].flag)
			{
				(*m)++;
				if (ren == 0)
					ren = flags[u].value;
				else
					ren |= flags[u].value;
				break;
			}

		if (flags[u].value == 0)
			break;
	}

	return (ren);
}
