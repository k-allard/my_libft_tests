/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr_strrch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:21:49 by kallard           #+#    #+#             */
/*   Updated: 2020/05/17 18:21:50 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

// Computes the length of the string.
// Returns the number of chars that precede the terminating '\0'.
size_t		ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

// Locates the first occurrence of c in the string str
char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (char *)(str + i);
		i++;
	}
	if (c == '\0')
		return (char *)(str + i);
	return (0);
}

// Locates the last occurrence of c in the string str.
char	*ft_strrchr(const char *str, int c)
{
	int len;

	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == c)
			return (char *)(str + len);
		len--;
	}
	return (0);
}

int main()
{
	char str[] = "procrastination";
	char *p;
	char *ft;
											//to test ft_strrchr:
	p = strchr(str, 'o');						//change strchr --> strrchr
	ft = ft_strchr(str, 'o');					//change ft_strchr --> ft_strrchr

	if (!(p))
		printf("Not found by original function");
	else 
		printf("Original function found \"%s\"", p);
	printf("\n_____\n");
	if (!(ft))
		printf("Not found by ft_function");
	else 
		printf("Ft_function found \"%s\"", ft);

	return 0;
}
