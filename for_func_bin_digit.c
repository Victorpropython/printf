#include "main.h"

/************************* PRINT INT *************************/
/**
 * convert_di - Print int
 * @args: Lista of arguments
 * @output: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: get width.
 * @prec: Precision specification
 * @len: Size specifier
 * Return: Number of chars printed
 */
unsigned int convert_digit(va_list args, buffer_v *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char pad, space = ' ', neg = '-', plus = '+';
	long int n, rep;
	unsigned int ren = 0, num = 0;

	if (len == LONG)
		n = va_arg(args, long int);
	else
		n = va_arg(args, int);
	if (len == SHORT)
		n = (short)n;
	if (SPACE_FLAG == 1 && n >= 0)
		ren += _memcpy(output, &space, 1);
	if (prec <= 0 && NEG_FLAG == 0)
	{
		if (n == LONG_MIN)
			num += 19;
		else
			for (rep = (n < 0) ? -n : n; rep > 0; rep /= 10)
				num++;
		num += (n == 0) ? 1 : 0;
		num += (n < 0) ? 1 : 0;
		num += (PLUS_FLAG == 1 && n >= 0) ? 1 : 0;
		num += (SPACE_FLAG == 1 && n >= 0) ? 1 : 0;
		if (ZERO_FLAG == 1 && PLUS_FLAG == 1 && n >= 0)
			ren += _memcpy(output, &plus, 1);
		if (ZERO_FLAG == 1 && n < 0)
			ren += _memcpy(output, &neg, 1);
		pad = (ZERO_FLAG == 1) ? '0' : ' ';
		for (wid -= num; wid > 0; wid--)
			ren += _memcpy(output, &pad, 1);
	}
	if (ZERO_FLAG == 0 && n < 0)
		ren += _memcpy(output, &neg, 1);
	if (ZERO_FLAG == 0 && (PLUS_FLAG == 1 && n >= 0))
		ren += _memcpy(output, &plus, 1);
	if (!(n == 0 && prec == 0))
		ren += convert_sbase(output, n, "0123456789",
				flags, 0, prec);
	ren += print_neg_width(output, ren, flags, wid);
	return (ren);
}
/************************* PRINT BINARY *************************/
/**
 * convert_binary - Prints an unsigned number
 * @args: Lista of arguments
 * @output: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: get width.
 * @prec: Precision specification
 * @len: Size specifier
 * Return: Numbers of char printed.
 */

unsigned int convert_bin_nums(va_list args, buffer_v *output,
	unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned int sum;

	sum = va_arg(args, unsigned int);
	(void)len;

	return (convert_ubase(output, sum, "01", flags, wid, prec));
}
