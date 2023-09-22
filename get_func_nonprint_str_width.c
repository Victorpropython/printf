#include "main.h"

/************************* PRINT NON PRINTABLE *************************/
/**
 * convert_non_printable - Prints ascii codes in hexa of non printable chars
 * @args: Lista of arguments
 * @output: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: get width
 * @prec: Precision specification
 * @len: Size specifier
 * Return: Number of chars printed
 */
unsigned int convert_non_printable(va_list args, buffer_v *output,
	unsigned char flags, int wid, int prec, unsigned char len)
{
	int count, ind;
	char *str, *null = "(null)", *hex = "\\x", zero = '0';
	unsigned int ren = 0;

	(void)len;
	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));
	for (count = 0; str[count];)
		count++;
	ren += print_string_width(output, flags, wid, prec, count);

	prec = (prec == -1) ? count : prec;
	for (ind = 0; *(str + ind) != '\0' && ind < prec; ind++)
	{
		if (*(str + ind) < 32 || *(str + ind) >= 127)
		{
			ren += _memcpy(output, hex, 2);
			if (*(str + ind) < 16)
			{
				ren += _memcpy(output, &zero, 1);
			}
			ren += convert_ubase(output, *(str + ind),
					"0123456789ABCDEF", flags, 0, 0);
			continue;
		}
		ren += _memcpy(output, (str + ind), 1);
	}
	ren += print_neg_width(output, ren, flags, wid);
	return (ren);
}

/*********************** TO PRINT STRING WIDTH ****************************/
/**
 *print_string_width - For space in buffer modifier
 *@output: A buffer
 *@wid: a width modifier
 *@flags: for flags
 *@prec: for precision
 *@count: the size of string
 *Return: the number of stored bytes
 */
unsigned int print_string_width(buffer_v *output,
		unsigned char flags, int prec, int wid, int count)
{
	char side = ' ';
	unsigned int ren = 0;

	if (NEG_FLAG == 0)
	{
		wid -= (prec == -1) ? count : prec;
		for (; wid > 0; wid--)
		{
			ren += _memcpy(output, &side, 1);
		}
	}
	return (ren);
}
