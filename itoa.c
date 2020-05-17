/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:20:52 by kallard           #+#    #+#             */
/*   Updated: 2020/05/17 18:20:53 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

// Duplicates a string by dynamically obtaining a block of memory.
// Returns a pointer to a new string.
char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	if (!(dest = (char*)malloc(sizeof(*dest) * (i + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// Counts number of digits in a positive integer.
int ft_digits(int n)
{
	int dig;
	
	dig = 1;
	while ((n /= 10) > 0) 
		dig++;
	return dig;
}

//Allocates and returns a string representing the int received as an argument.
char	*ft_itoa(int n)
{
	char	*str;
	int		negative;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	negative = 0;
	if (n < 0)
	{
		negative = 1;
		n = -n;
	}
	len = ft_digits(n) + negative;
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (negative)
		str[0] = '-';
	str[len--] = '\0';
	while (len >= negative)
	{
		str[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}

int main()
{
	int n = 2147483647;
	printf("[%s]\n", ft_itoa(n));
	return 0;
}
