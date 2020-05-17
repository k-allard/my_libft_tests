/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:21:55 by kallard           #+#    #+#             */
/*   Updated: 2020/05/17 18:21:56 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <stdlib.h>

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

// Allocates and returns a new string, 
// Which is the result of the concatenation of ’s1’ and ’s2’.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(dest = (char*)malloc(sizeof(*dest) * (len1 + len2 + 1))))
		return (NULL);
	i = 0;
	while (i < len1)
	{
		dest[i] = s1[i];
		i++;
	}
	while (i < (len1 + len2))
	{
		dest[i] = s2[i - len1];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int main()
{
    char *str1 = "my plant has just ";
	char *str2;

	str2 = "grown a new leaf";
	printf ("Return string is: \"%s\"\n", ft_strjoin(str1, str2));
	return 0;
}
