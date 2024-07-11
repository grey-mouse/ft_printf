/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niarygin <niarygin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:59:03 by niarygin          #+#    #+#             */
/*   Updated: 2024/07/11 12:26:40 by niarygin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char c)
{
	write(1, &c, 1);
}
char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != (char) c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)(s + i));
}
void	print_fmt_char(t_format *fmt, va_list args)
{
	char	c;
	
	c = va_arg(args, int);
	if (fmt->width > 0)
		fmt->offset = fmt->width - 1;
	fmt->len += fmt->offset + 1;
	if (fmt->minus)
	{
		print_char(c);
		while (fmt->offset--)
			print_char(' ');
	}
	else
	{
		while (fmt->offset--)
			print_char(' ');
		print_char(c);
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	print_string(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

void	print_len_string(char *s, int len)
{
	write(1, s, len);
}

void	print_fmt_string(t_format *fmt, va_list args)
{
	size_t		len;
	const char	*str;
	
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (!fmt->dot || fmt->precision > len)
		fmt->precision = len;
	if (fmt->width > fmt->precision)
		fmt->offset = fmt->width - fmt->precision;
	fmt->len += fmt->offset + fmt->precision;
	if (fmt->minus)
	{
		print_string((char *)str);
		while (fmt->offset--)
			print_char(' ');
	}
	else
	{
		while (fmt->offset--)
			print_char(' ');
		print_len_string((char *)str, fmt->precision);
	}
}