/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niarygin <niarygin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:01:27 by niarygin          #+#    #+#             */
/*   Updated: 2024/07/04 13:57:54 by niarygin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int		count;
	char	c;
	char	*s;

	count = 0;
	printf("\nTest0: simple string without specifiers\n");
	printf("Expected string: |");
	count = printf("Hello, World!");
	printf("|\nExpected count: %i\n", count);
	printf("Actual string: |");
	fflush(stdout);
	count = ft_printf("Hello, World!");
	printf("|\nActual count: %i\n", count);

	printf("\nTest1: string with %%c specifier\n");
	c = 'A';
	printf("Expected string: |");
	count = printf("Hello, %c and World!", c);
	printf("|\nExpected count: %i\n", count);
	printf("Actual string: |");
	fflush(stdout);
	count = ft_printf("Hello, %c and World!", c);
	printf("|\nActual count: %i\n", count);

	printf("\nTest2: string with %%s specifier\n");
	s = "Hello, World!";
	printf("Expected string: |");
	count = printf("Hello, %s and World!", s);
	printf("|\nExpected count: %i\n", count);
	printf("Actual string: |");
	fflush(stdout);
	count = ft_printf("Hello, %s and World!", s);
	printf("|\nActual count: %i\n", count);
	
	return (0);
}