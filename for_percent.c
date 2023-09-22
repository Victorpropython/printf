/************************* PRINT PERCENT SIGN *************************/
/**
 * convert_percent - Prints a percent sign
 * @args: Lista of arguments
 * @output: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: get width.
 * @prec: Precision specification
 * @len: Size specifier
 * Return: Number of chars printed
 */
unsigned int percent_sign(va_list args, buffer_v *output,
	unsigned char flags, int wid, int prec, unsigned char len)
{
	char percent = '%';
	unsigned int ren = 0;

	(void)args;
	(void)prec;
	(void)len;

	ren += print_width(output, ren, flags, wid);
	ren += _memcpy(output, &percent, 1);
	ren += print_neg_width(output, ren, flags, wid);

	return (ren);
}
