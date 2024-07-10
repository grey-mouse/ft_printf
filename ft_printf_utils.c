/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niarygin <niarygin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:59:03 by niarygin          #+#    #+#             */
/*   Updated: 2024/07/10 15:22:14 by niarygin         ###   ########.fr       */
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
	const char	c = va_arg(args, int);

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

/*int	print_string(char *s)
{
	unsigned int	i;
	
	i = 0;
	while (s[i])
	{
		print_char(s[i]);
		i++;
	}
	return (i);
}

int	print_addr(void *p)
{
	(void)p;
	return (1);
}*/
