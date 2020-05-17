/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:22:16 by kallard           #+#    #+#             */
/*   Updated: 2020/05/17 18:22:17 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <stdlib.h>

// Computes the length of the string (not including the terminating '\0').
size_t		ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

// Writes len bytes of value c (converted to an unsigned char) to the string b.
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *p;

	p = (unsigned char*)b;
	while (len--)
		*p++ = (unsigned char)c;
	return (b);
}

// Allocates memory for count objects that are size bytes each.
// Fills the allocated memory with zeros.
// Returns a pointer to the allocated memory.
void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	if (!(ptr = (char *)malloc(count * size)))
		return (NULL);
	return (ft_memset(ptr, 0, count * size));
}

// Dynamically allocates and returns a substring from the string ’s’.
// The substring begins at index ’start’ and is of maximum size ’len’.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (i < start || (i - start) < len)
		return (char *)(ft_calloc(1, sizeof(s[0])));
	i = 0;
	if (!(dest = (char*)malloc(sizeof(*dest) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int main()
{
    char *str = "my plant has just grown a new leaf";
	printf ("Return string is: \"%s\"\n", ft_substr(str, 26, 3));
	printf ("Return string is: \"%s\"\n", ft_substr(str, 3, 5));
	return 0;
}
