#include "main.h"
/**
 * handle_specifiers - Prints an argument based on its type
 * @*: for integer variable
 * @char: for char variable
 * @int: for number
 * Return: 1 or 2;
 */
unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_v *,
	unsigned char, int, int, unsigned char)
{
	int i;
	converter_v converters[] = {
		{'c', convert_alpha},
		{'s', convert_str},
		{'%', percent},
		{'i', convert_digit},
		{'d', convert_digit},
		{'b', convert_bin_nums},
		{'u', change_unsignd},
		{'o', change_octal},
		{'x', change_hexadecimal},
		{'X', change_hexa_upper},
		{'p', change_pointer},
		{'S', change_non_printable},
		{'r', change_reverse},
		{'R', change_rot13str},
		{'\0', NULL}

	};

	for (i = 0; converters[i].func; i++)
	{
		if (converters[i].specifier == *specifier)
		{
			return (converters[i].func);
		}
	}
	return (NULL);
}
