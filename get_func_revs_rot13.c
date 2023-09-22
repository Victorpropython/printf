#include "main.h"
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * change_rot13string - Print a string in rot13.
 * @args: Lista of arguments
 * @output: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: get width
 * @prec: Precision specification
 * @len: Size specifier
 * Return: Numbers of chars printed
 */
unsigned int change_rot13str(va_list args, buffer_v *output,
        unsigned char flags, int wid, int prec, unsigned char len)
{
        char *str, *nul = "(null)";
        unsigned int ren = 0;
        int i, j, count;
        char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

        str = va_arg(args, char *);
        if (str == NULL)
                return (_memcpy(output, nul, 6));
        for (count = 0; *(str + count);)
                count++;
        ren += print_string_width(output, flags, wid, prec, len);
        prec = (prec == -1) ? count : prec;
        for (i = 0; *(str + i) != '\0' && i < prec; i++)
        {
                for (j = 0; j < 52; j++)
                {
                        if (*(str + i) == *(alpha + j))
                        {
                                ren += _memcpy(output, (rot13 + j), 1);
                                break;
                        }
                }
                if (j == 52)
                {
                        ren += _memcpy(output, (str + i), 1);
                }
        }
	ren += print_neg_width(output, ren, flags, wid);
	return (ren);
}

/************************* PRINT REVERSE *************************/
/**
 * convert_reverse - Prints reverse string.
 * @args: Lista of arguments
 * @output: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: get width
 * @prec: Precision specification
 * @len: Size specifier
 * Return: Numbers of chars printed
 */

unsigned int change_reverse(va_list args, buffer_v *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *str, *null = "(null)";
	int i, count, end;
	unsigned int ren = 0;

	(void)flags;
	(void)len;

	str = va_arg(args, char *);

	if (str == NULL)
	{
		return (_memcpy(output, null, 6));
	}
	for (count = 0; *(str + count);)
		count++;
	ren += print_string_width(output, flags, wid, prec, count);
	end = count - 1;
	prec = (prec == 1) ? count : prec;

	for (i = 0; end >= 0 && i < prec; i++)
	{
		ren += _memcpy(output, (str + end), 1);
		end++;
	}

	ren += print_neg_width(output, ren, flags, wid);
	return (ren);
}
