#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * convert_char - Prints a char
 * @args: List a of arguments
 * @display: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: Width
 * @prec: Precision specification
 * @len: Size specifier
 * Return: Number of chars printe
 */
unsigned int convert_char(va_list args, buffer_t *display,
	unsigned char flags, int wid, int prec, unsigned char len)
{
	char c = va_arg(args, int);
	unsigned int ren = 0;

	(void)prec;
	(void)len;

	ren += _memcpy(display, &c, 1);
	ren += print_width(display, ren, flags, wid);
	ren += print_neg_width(display, ren, flags, wid);

	return (ren);
}
/************************* PRINT A STRING *************************/
/**
 * pconvert_string - Prints a string
 * @args: List a of arguments
 * @output: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: get width.
 * @prec: Precision specification
 * @len: Size specifier
 * Return: Number of chars printed
 */
unsigned int convert_string(va_list args, buffer_t *output,
	unsigned char flags, int wid, int prec, unsigned char len)
{
	int count;
	unsigned int ren = 0;
	char *str, *null = "(null)";

	(void)len;
	(void)flags;
	str = va_arg(args, char *);
	if (str == NULL)
	{
		return (_memcpy(output, null, 6));
	}
	for (count = 0; *(str + count);)
		count++;
	ren += print_string_width(output, flags, wid, prec, count);
	prec = (prec == -1) ? count : prec;
	while (*str != '\0' && prec > 0)
	{
		ren += _memcpy(output, str, 1);
		prec--;
		str++;
	}
	ren += print_neg_width(output, ren, flags, wid);

	return (ren);
}
