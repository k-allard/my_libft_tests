/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:20:20 by kallard           #+#    #+#             */
/*   Updated: 2020/05/17 18:20:21 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

# define LLMAX 		9223372036854775807ull

int	ft_isspace(int ch)
{
	if (ch == '\t' || ch == '\n' || ch == '\v' ||
		ch == '\f' || ch == '\r' || ch == ' ')
		return (1);
	return (0);
}

// Converts ASCII string to integer.
// Is intended to imitate the behaviour of original atoi,
// which has undefined behavior if the value of the result cannot be represented.
int	ft_atoi(char *str)
{
	unsigned long long	result;
	int					length_max;
	int					sign;
	int					i;

	result = 0;
	length_max = 19;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = str[i++] == '-' ? -1 : 1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i++] - '0';
		if (length_max-- < 0)
			return (sign == 1 ? -1 : 0);
		if (result >= LLMAX && sign == 1)
			return (-1);
		if (result > LLMAX && sign == -1)
			return (0);
	}
	return (sign * result);
}

int main()
{
	char *n[] = {"99999999999999999999999999", \
  				"9323372036854775807", "-92233720368547758072", "9223372036854775809", \
				"9223372036854775808", "9223372036854775807", "9223372036854775806", \
    			"", "           ", "XXX", "2222222222222222222222", "21474836499999", \
				"2147483649", "2147483648", "2147483647", "2147483646", "+ 2", \
				"   +  2   ", "\t \t \t + \t 2 \t ", "+2", " +2", "+2 ",  " +2 ",\
    			"2", "+0", "0", "-0", "+", "-", "+ 0", "- 0", "-2147483646", "-2147483647", \
				"-2147483648", "-2147483649", "-9223372036854775806", "-9223372036854775807", \
    			"-9223372036854775808", "-9223372036854775809", "-99999999999999999999999999"};

	printf("\n\x1b[42m _____________________ \x1b[0m\n");
	printf("\x1b[42m| [INPUT STRING]      |\x1b[0m\n");
	printf("\x1b[42m| ORIGINAL == FT_ATOI |\x1b[0m\n");
	printf("\x1b[42m _____________________ \x1b[0m\n\n");

	int size = sizeof n / sizeof n[0];

	for (int i = 0; i < size; i++)
	{
		int atoi_int = atoi(n[i]);
		int ft_atoi_int = ft_atoi(n[i]);
		if (atoi_int == ft_atoi_int)
			printf("[%s]\n\x1b[1;32m%d == %d\x1b[0m\n\n", n[i], atoi_int, ft_atoi_int);
		else
			printf("[%s]\n\x1b[1;31m%d == %d\x1b[0m\n\n", n[i], atoi_int, ft_atoi_int);
	}
	return(0);
}
