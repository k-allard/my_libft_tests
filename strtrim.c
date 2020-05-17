/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:22:14 by kallard           #+#    #+#             */
/*   Updated: 2020/05/17 18:22:15 by kallard          ###   ########.fr       */
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
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

    if (!s)
        return (NULL);
	i = ft_strlen(s);
	if (start > i || len > (i - start))
		return (char *)(ft_calloc(1, sizeof(s[0])));
	i = 0;
	if (!(dest = (char*)malloc(sizeof(*dest) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		dest[i] = s[start + i];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}

// Writes n zeroed bytes to the string s.
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = 0;
}

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

// Removes chars specified in ’set’ from the beginning and the end of string s1.
// Allocates and returns a copy of s1 modified.
char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	end;
	size_t			setlen;
	unsigned char	trim_hashmap[256];

	if (!s1 || !set)
		return (NULL);
	setlen = ft_strlen(set);
	if (!setlen || !ft_strlen(s1))
		return (ft_strdup(s1));
	ft_bzero(trim_hashmap, 256);
	i = 0;
	while (i < setlen)
		trim_hashmap[(unsigned int)set[i++]] = 1;
	i = 0;
	end = ft_strlen(s1) - 1;
	while (s1[i] && trim_hashmap[(unsigned int)s1[i]])
		i++;
	while (end > i && trim_hashmap[(unsigned int)s1[end]])
		end--;
	return (ft_substr(s1, i, end - i + 1));
}

int main()
{
    char *s1 = "  procrastination...      ";
	char *set = " .";

	printf ("New string is: \"%s\"\n", ft_strtrim(s1, set));
	return 0;
}
