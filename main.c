/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niarygin <niarygin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:01:27 by niarygin          #+#    #+#             */
/*   Updated: 2024/07/10 15:18:02 by niarygin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int		count;
	char	c, d;
	//char	*s;

	count = 0;
	printf("\nTest0: simple string without specifiers\n");
	printf("Expected string: |");
	count = printf("Hello, World!");
	printf("|\nExpected count: %i\n", count);
	printf("Actual string  : |");
	fflush(stdout);
	count = ft_printf("Hello, World!");
	printf("|\nActual count  : %i\n", count);

	printf("\nTest1.0: string with %%c specifier\n");
	c = 'A';
	printf("Expected string: |");
	count = printf("Hello, |%c| and World!", c);
	printf("|\nExpected count: %i\n", count);
	printf("Actual string  : |");
	fflush(stdout);
	count = ft_printf("Hello, |%c| and World!", c);
	printf("|\nActual count  : %i\n", count);

	printf("\nTest1.0: string with several %%c specifiers\n");
	c = 'A';
	d = 'B';
	printf("Expected string: |");
	count = printf("Hello, |%c%c| and World!", c, d);
	printf("|\nExpected count: %i\n", count);
	printf("Actual string  : |");
	fflush(stdout);
	count = ft_printf("Hello, |%c%c| and World!", c, d);
	printf("|\nActual count  : %i\n", count);

	printf("\nTest1.1: string with %%c and width (%%5c)\n");
	c = 'A';
	printf("Expected string: |");
	count = printf("Hello, |%5c| and World!", c);
	printf("|\nExpected count: %i\n", count);
	printf("Actual string  : |");
	fflush(stdout);
	count = ft_printf("Hello, |%5c| and World!", c);
	printf("|\nActual count  : %i\n", count);

	printf("\nTest1.1.1: string with %%c and width (%%1c)\n");
	c = 'A';
	printf("Expected string: |");
	count = printf("Hello, |%1c| and World!", c);
	printf("|\nExpected count: %i\n", count);
	printf("Actual string  : |");
	fflush(stdout);
	count = ft_printf("Hello, |%1c| and World!", c);
	printf("|\nActual count  : %i\n", count);

	printf("\nTest1.1.2: string with %%c and width (%%10c)\n");
	c = 'A';
	printf("Expected string: |");
	count = printf("Hello, |%10c| and World!", c);
	printf("|\nExpected count: %i\n", count);
	printf("Actual string  : |");
	fflush(stdout);
	count = ft_printf("Hello, |%10c| and World!", c);
	printf("|\nActual count  : %i\n", count);

	printf("\nTest1.1.3: string with only %%c and width (%%10c)\n");
	c = 'A';
	printf("Expected string: |");
	count = printf("%10c", c);
	printf("|\nExpected count: %i\n", count);
	printf("Actual string  : |");
	fflush(stdout);
	count = ft_printf("%10c", c);
	printf("|\nActual count  : %i\n", count);

	printf("\nTest1.1.4: string with several %%c and width (%%10c)\n");
	c = 'A';
	d = 'B';
	printf("Expected string: |");
	count = printf("%10c%5c", c, d);
	printf("|\nExpected count: %i\n", count);
	printf("Actual string  : |");
	fflush(stdout);
	count = ft_printf("%10c%5c", c, d);
	printf("|\nActual count  : %i\n", count);

	/*printf("\nTest1.2: string with %%c and width and minus - (%%-10c)\n");
	c = 'A';
	printf("Expected string: |");
	count = printf("Hello, |%-10c| and World!", c);
	printf("|\nExpected count: %i\n", count);
	printf("Actual string  : |");
	fflush(stdout);
	count = ft_printf("Hello, |%-10c| and World!", c);
	printf("|\nActual count  : %i\n", count);*/

	/*printf("\nTest1.2.1: string with %%c and minus - (%%-c)\n");
	c = 'A';
	printf("Expected string: |");
	count = printf("Hello, |%-c| and World!", c);
	printf("|\nExpected count: %i\n", count);
	printf("Actual string  : |");
	fflush(stdout);
	count = ft_printf("Hello, |%-c| and World!", c);
	printf("|\nActual count  : %i\n", count);*/


	/*printf("\nTest2: string with %%s specifier\n");
	s = "Hello, World!";
	printf("Expected string: |");
	count = printf("Hello, %s and World!", s);
	printf("|\nExpected count: %i\n", count);
	printf("Actual string: |");
	fflush(stdout);
	count = ft_printf("Hello, %s and World!", s);
	printf("|\nActual count: %i\n", count);*/
	
	return (0);
}