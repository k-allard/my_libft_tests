/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 13:56:02 by kallard           #+#    #+#             */
/*   Updated: 2020/05/17 14:52:52 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

char	to_upper_case(unsigned int n, char ch)
{
	if (ch >= 'a' && ch <= 'z')
		ch = ch - ('a' - 'A');
	return (ch);
}


// Copies the string s to a new string dynamically allocated.
// Applies the function ’f’ to each char of the new string.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;
	
	if (!s || !f)
		return (NULL);
	if (!(dest = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	while (s[i])
		{
			dest[i] = (*f)(i, s[i]);
			i++;
		}
	dest[i] = '\0';
	return (dest);
}

int main()
{
	char *src = "abc 123";
	printf("\nSrc string is: \"%s\"", src);
	printf("\nSrc string adress: %p\n", src);
    char *dest;
    printf("\nDuplicating with to_upper_case function. . .\n");
    dest = ft_strmapi(src, to_upper_case);
    printf("\nDest string is: \"%s\"", dest);
	printf("\nDest string adress: %p\n", dest);
	
	return 0;
}
