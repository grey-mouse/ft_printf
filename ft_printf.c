/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niarygin <niarygin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:15:36 by niarygin          #+#    #+#             */
/*   Updated: 2024/06/25 10:48:43 by niarygin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

int	ft_printf(const char *format, ...)
{
	char	cval;
	int		i;
	int		count;
	
	va_list	arg_ptr;
	va_start(arg_ptr, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			i++;
			count++;
			continue;
		}
		i++;
		if (format[i] == 'c')
		{
			cval = va_arg(arg_ptr, int);
			ft_putchar_fd(cval, 1);
			count++;
			i++;
		}
	}
	va_end(arg_ptr);
	return (count);
}
