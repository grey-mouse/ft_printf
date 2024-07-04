/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niarygin <niarygin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:15:36 by niarygin          #+#    #+#             */
/*   Updated: 2024/07/04 14:00:23 by niarygin         ###   ########.fr       */
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

static int	print_format(va_list arg_ptr, const char *format, unsigned int i)
{	
	if (format[i] == 'c')
		return(print_char(va_arg(arg_ptr, int)));
	else if (format[i] == 's')
		return(print_string(va_arg(arg_ptr, char *)));
	else
		return (-1);
}

int	ft_printf(const char *format_str, ...)
{
	unsigned int	i;
	unsigned int	count;
	va_list			arg_ptr;
	
	va_start(arg_ptr, format_str);
	i = 0;
	count = 0;
	while (format_str[i])
	{
		if (format_str[i] != '%')
		{
			count += print_char(format_str[i]);
		}
		else if (format_str[i] == '%' && ft_strchr("cspdiuxX%", format_str[i + 1]))
		{
			count += print_format(arg_ptr, format_str, i + 1);
			i++;
		}
		i++;	
	}
	va_end(arg_ptr);
	return (count);
}
