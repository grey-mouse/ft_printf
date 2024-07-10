/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niarygin <niarygin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:15:36 by niarygin          #+#    #+#             */
/*   Updated: 2024/07/10 14:45:00 by niarygin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//The function implements the following conversions:
// %c Prints a single character.
// %s Prints a string (as defined by the common C convention).
// %p The void * pointer argument has to be printed in hexadecimal format.
// %d Prints a decimal (base 10) number.
// %i Prints an integer in base 10.
// %u Prints an unsigned decimal (base 10) number.
// %x Prints a number in hexadecimal (base 16) lowercase format.
// %X Prints a number in hexadecimal (base 16) uppercase format.
// %% Prints a percent sign.
//
//Bonus: 
//Manage any combination of the following flags: ’-0.’ 
//and the field minimum width under all conversions.
//(and/or) Manage all the following flags: ’# +’.

/*
			len; -length of the printed word
			offset; -
			pad; - 
			width; - width parameter, e.g. width=25 in printf("%25s", str);
			precision; - for int the minimum num of symbols to print, result isn't truncated, 
			adds leading zeroes
			hashtag; - used with x, X, the value is preceded with 0x, 0X
			zero; - left-pads number with zeroes instead of spaces where width specified
			minus; - left-justify within the given width
			space; -if no sign then space is inserted before the value
			plus; - forces to precede result with + or - for numbers
			dot; - is there . or not
			upper; - x or X
*/

static void format_init(t_format *fmt)
{
	fmt->minus = false;
	fmt->zero = false;
	fmt->dot = false;
	fmt->precision = 0;
	fmt->hashtag = false;
	fmt->space = false;
	fmt->plus = false;
	fmt->width = 0;
	fmt->offset = 0;
	//fmt->pad_ = 0;
	//fmt->upper_ = 0;
}

static void	set_format_values(char c, t_format *fmt)
{
	if (c >= '0' && c <= '9')
	{
		if (fmt->dot || fmt->zero)
			fmt->precision = fmt->precision * 10 + c - '0';
		else
		{
			if (!fmt->width && c == '0')
				fmt->zero = true;
			else
				fmt->width = fmt->width * 10 + c - '0';
		}
	}
	else if (c == '-')
		fmt->minus = true;
	else if (c == '.')
		fmt->dot = true;
	else if (c == '#')
		fmt->hashtag = true;
	else if (c == ' ')
		fmt->space = true;
	else if (c == '+')
		fmt->plus = true;
}

static const char	*print_format(const char *f_string, t_format *fmt, va_list args)
{	
	while (*f_string && !ft_strchr("cspdiuxX%", *f_string))
		set_format_values(*f_string++, fmt);
	if (*f_string == 'c')
		print_fmt_char(fmt, args);
	/*else if (*f_string == 's')
		return (print_string(va_arg(arg_ptr, char *)));
	else if (*f_string == 'p')
		return (print_addr(va_arg(arg_ptr, void *)));*/
	return (++f_string);
}

int	ft_printf(const char *f_string, ...)
{
	int			count;
	t_format	fmt;
	va_list		args;

	count = 0;
	fmt.len = 0;
	format_init(&fmt);
	va_start(args, f_string);
	while (*f_string)
	{
		if (*f_string == '%' && *f_string++)
		{
			f_string = print_format(f_string, &fmt, args);
			format_init(&fmt);
		}
		else if (++count)
			print_char(*f_string++);
	}
	va_end(args);
	count += fmt.len;
	return (count);
}
