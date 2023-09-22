#include "main.h"

/********************PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * convert_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @args: Names or Number of arguments
i * @output: Container array to hold print
 * @flags:  Calculates flags that are active
 * @wid: To get width length
 * @prec: Precise Definitions
 * @len: Size specifier
 * Return: The hexadecimal number
 */
unsigned int convert_hexadecimal(va_list args, buffer_t *output,
	unsigned char flags, int wid, int prec, unsigned char len)
{
	char *top = "0x";
	unsigned int ren = 0;
	unsigned long int digit;

	if (len == LONG)
	{
		digit = va_arg(args, unsigned long int);
	}
	else
		digit = va_arg(args, unsigned int);
	if (len == SHORT)
	{
		digit = (unsigned short)digit;
	}
	if (HASH_FLAG == 1 && digit != 0)
	{
		ren += _memcpy(output, top, 2);
	}
	if (!(digit == 0 && prec == 0))
	{
		ren += convert_ubase(output, digit, "0123456789abcdef",
				flags, wid, prec);
	}
	ren += print_neg_width(output, ren, flags, wid);
	return (ren);
}
/**
 * convert_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @args: List of arguments
 * @output: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: get width
 * @prec: Precision specification
 * @len: Size specifier
 * Return: Number of chars printed
 */
unsigned int convert_hexa_upper(va_list args, buffer_t *output,
	unsigned char flags, int wid, int prec, unsigned char len)
{
	char *top = "0X";
	unsigned long int digit;
	unsigned int ren = 0;

	if (len == LONG)
	{
		digit = va_arg(args, unsigned long);
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
		ren += _memcpy(output, top, 2);
	if (!(digit == 0 && prec == 0))
	{
		ren += convert_ubase(output, digit, "0123456789ABCDEF",
				flags, wid, prec);
	}
	ren += print_neg_width(output, ren, flags, wid);
	return (ren);
}

/**
 * convert_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @args: List of arguments
 * @output: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: get width
 * @prec: Precision specification
 * @len: Size specifier
 * Return: Number of chars printed
 */
unsigned int convert_hexa_upper(va_list args, buffer_t *output,
	unsigned char flags, int wid, int prec, unsigned char len)
{
	char *top = "0X";
	unsigned long int digit;
	unsigned int ren = 0;

	if (len == LONG)
	{
		digit = va_arg(args, unsigned long);
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
		ren += _memcpy(output, top, 2);
	if (!(digit == 0 && prec == 0))
	{
		ren += convert_ubase(output, digit, "0123456789ABCDEF",
				flags, wid, prec);
	}
	ren += print_neg_width(output, ren, flags, wid);
	return (ren);
}
