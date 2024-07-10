/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niarygin <niarygin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:59:17 by niarygin          #+#    #+#             */
/*   Updated: 2024/07/10 15:18:42 by niarygin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct s_format
{
	unsigned int	len;
	bool			minus;
	bool			zero;
	bool			dot;
	unsigned int	precision;
	bool			hashtag;
	bool			space;
	bool			plus;
	unsigned int	width;
	int				offset;
}	t_format;

int		ft_printf(const char *format, ...);
char	*ft_strchr(const char *s, int c);
void	print_char(char c);
void	print_fmt_char(t_format *fmt, va_list args);
//int		print_string(char *s);
//int		print_addr(void *p);

#endif