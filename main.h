#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

/* Flag Modifier Macros */
#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define PLUS_FLAG (flags & 1)
#define SPACE_FLAG ((flags >> 1) & 1)
#define HASH_FLAG ((flags >> 2) & 1)
#define ZERO_FLAG ((flags >> 3) & 1)
#define NEG_FLAG ((flags >> 4) & 1)

/* Length Modifier Macros */
#define SHORT 1
#define LONG 2

/**
 * struct buffer_sh - A new type defining a buffer struct.
 * @buffer: A pointer to a character array.
 * @start: A pointer to the start of buffer.
 * @len: The length of the string stored in buffer.
 */
typedef struct buffer_sh
{
	char *buffer;
	char *start;
	unsigned int len;
} buffer_v;

/**
 * struct converter_sh - A new type defining a converter struct.
 * @specifier: A character representing a conversion specifier.
 * @func: A pointer to a conversion function corresponding to specifier.
 */
typedef struct converter_sh
{
	unsigned char specifier;
	unsigned int (*func)(va_list, buffer_v *,
			unsigned char, int, int, unsigned char);
} converter_v;
/**
 * struct flag_sh - A new type defining a flags struct.
 * @flag: A character representing a flag.
 * @value: The integer value of the flag.
 */
typedef struct flag_sh
{
	unsigned char flag;
	unsigned char value;
} flag_v;

int _printf(const char *format, ...);


/* Conversion Specifier Functions */
unsigned int convert_alpha(va_list args, buffer_v *display,
	unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_str(va_list args, buffer_v *output,
	unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_digit(va_list args, buffer_v *output,
	unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_percent(va_list args, buffer_v *output,
	unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_bin_nums(va_list args, buffer_v *output,
	unsigned char flags, int wid, int prec, unsigned char len);
unsigned int change_unsignd(va_list args, buffer_v *output,
	unsigned char flags, int wid, int prec, unsigned char len);
unsigned int change_octal(va_list args, buffer_v *output,
	unsigned char flags, int wid, int prec, unsigned char len);
unsigned int change_hexadecimal(va_list args, buffer_v *output,
	unsigned char flags, int wid, int prec, unsigned char len);
unsigned int change_hexa_upper(va_list args, buffer_v *output,
	unsigned char flags, int wid, int prec, unsigned char len);
unsigned int change_non_printable(va_list args, buffer_v *output,
	unsigned char flags, int wid, int prec, unsigned char len);
unsigned int change_pointer(va_list args, buffer_v *output,
	unsigned char flags, int wid, int prec, unsigned char len);
unsigned int change_reverse(va_list args, buffer_v *output,
	unsigned char flags, int wid, int prec, unsigned char len);
unsigned int change_rot13str(va_list args, buffer_v *output,
	unsigned char flags, int wid, int prec, unsigned char len);
/* Handlers */
unsigned char handle_flags(const char *flags, char *m);
unsigned char handle_length(const char *modifier, char *i);
int handle_width(va_list args, const char *modifier, char *i);
int handle_precision(va_list args, const char *modifier, char *);
unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_v *,
		unsigned char, int, int, unsigned char);


/* FOR PARSER */
buffer_v *init_buffer(void);
void free_buffer(buffer_v *output);
unsigned int _memcpy(buffer_v *output, const char *src, unsigned int m);
unsigned int convert_sbase(buffer_v *output, long int num, char *base,
		unsigned char flags, int wid, int prec);
unsigned int convert_ubase(buffer_v *output, unsigned long int num, char *base,
		unsigned char flags, int wid, int prec);

/*Utils*/
unsigned int print_width(buffer_v *output, unsigned int display,
		unsigned char flags, int wid);
unsigned int print_string_width(buffer_v *output,
		unsigned char flags, int wid, int prec, int count);
unsigned int print_neg_width(buffer_v *output, unsigned int display,
		unsigned char flags, int wid);
#endif /* MAIN_H */
