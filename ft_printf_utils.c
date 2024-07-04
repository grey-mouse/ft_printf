/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niarygin <niarygin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:59:03 by niarygin          #+#    #+#             */
/*   Updated: 2024/07/04 13:44:56 by niarygin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
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
int	print_string(char *s)
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
