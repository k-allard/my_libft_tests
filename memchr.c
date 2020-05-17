/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:21:28 by kallard           #+#    #+#             */
/*   Updated: 2020/05/17 18:21:29 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ** Locates the first occurrence of char c in string s.
// ** Returns a pointer to it or NULL if it doesn't exist within n bytes.
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int		i;
	unsigned const char	*p;

	p = (unsigned const char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)(c) == (unsigned const char)(p[i]))
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}

int main()
{
	char str[] = "procrastination";
	char *p;
	char *ft;
											//to test ft_strrchr:
	p = memchr(str, 'o', 16);						//change strchr --> strrchr
	ft = ft_memchr(str, 'o', 16);					//change ft_strchr --> ft_strrchr

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
