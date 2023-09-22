#include "main.h"
/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * convert_octal - Prints an unsigned number in octal notation
 * @args: Lista of arguments
 * @output: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: get width
 * @prec: Precision specification
 * @len: Size specifier
 * Return: Number of chars printed
 */
unsigned int change_octal(va_list args, buffer_v *output,
	unsigned char flags, int wid, int prec, unsigned char len)
{

	unsigned long int digit;
	unsigned int ren = 0;
	char zero = '0';

	if (len == LONG)
	{
		digit = va_arg(args, unsigned long int);
	}
	else
	{
		digit = va_arg(args, unsigned int);
	}
	if (len == SHORT)
	{
		digit = (unsigned short)digit;
	}

	if (HASH_FLAG == 1 && digit != 0)
	{
		ren += _memcpy(output, &zero, 1);
	}
	if (!(digit == 0 && prec == 0))
	{
		ren += convert_ubase(output, digit, "01234567",
				flags, wid, prec);
	}
	ren += print_neg_width(output, ren, flags, wid);
	return (ren);
}
/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * convert_unsignd - To print unsigned number
 * @args: List a of arguments
 * @output: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: get width
 * @prec: Precision specification
 * @len: Size specifier
 * Return: Number of chars printed.
 */

unsigned int change_unsignd(va_list args, buffer_v *output,
	unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned int digit;
	unsigned long int ren = 0;

	if (len == LONG)
	{
		digit = va_arg(args, unsigned long int);
	}
	else
	{
		digit = va_arg(args, unsigned int);
	}
	if (len == SHORT)
	{
		digit = (unsigned short)digit;
	}
	if (!(digit == 0 && prec == 0))
	{
		ren += convert_ubase(output, digit, "0123456789",
				flags, wid, prec);
	}
	ren += print_neg_width(output, ren, flags, wid);
	return (ren);
}
/************** TO PRINT HEXA NUMS IN LOW OR UPPER CASE **************/
/**
 * convert_pointer - Prints a hexadecimal number in lower or upper
 * @args: Lista of arguments
 * @output: Array of values for buffer  number
 * @flags:  Calculates active flags
 * @wid: get width
 * @prec: Precision specification
 * @len: Size specification
 * Return: Number of chars printed
 */
unsigned int change_pointer(va_list args, buffer_v *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *nul = "(nil)";
	unsigned long int num;
	unsigned int ren = 0;

	(void)len;
	num = va_arg(args, unsigned long int);
	if (num == '\0')
	{
		return (_memcpy(output, nul, 5));
	}
	flags |= 32;
	ren += convert_ubase(output, num, "0123456789abcdef", flags,
			wid, prec);
	ren += print_neg_width(output, ren, flags, wid);
	return (ren);
}
