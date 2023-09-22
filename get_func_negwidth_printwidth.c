#include "main.h"
/**
 *print_neg_width - To keep a space to a buffer for the '-' flag
 *@output: A buffer struct
 *@display: Number of bytes
 *@flags: for flags
 *@wid: for width
 *Return: The number of bytes
 */
unsigned int print_neg_width(buffer_t *output, unsigned int display,
		unsigned char flags, int wid)
{
	unsigned int ren = 0;
	char side = ' ';

	if (NEG_FLAG == 1)
	{
		for (wid -= display; wid > 0; wid--)
		{
			ren += _memcpy(output, &side, 1);
		}
	}
	return (ren);
}
/************************* FOR PRINT OF WIDTH *****************************/
/**
 *print_width - store a leading space for the modifier
 *@output: A buffer struct
 *@display: The number of char bytes
 *@flags: for flags
 *@wid: For width
 *Return: The number of bytes
 */
unsigned int print_width(buffer_t *output, unsigned int display,
		unsigned char flags, int wid)
{
	char side = ' ';
	unsigned int ren = 0;

	if (NEG_FLAG == 0)
	{
		for (wid -= display; wid > 0;)
		{
			ren += _memcpy(output, &side, 1);
		}
	}
	return (ren);
}
