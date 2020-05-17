/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:21:47 by kallard           #+#    #+#             */
/*   Updated: 2020/05/17 18:21:48 by kallard          ###   ########.fr       */
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

// Duplicates a string by dynamically obtaining a block of memory.
// Returns a pointer to a new string.
char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	i;

	if (!src)
		return (NULL);
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

// Writes n zeroed bytes to the string s.
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = 0;
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

// Removes chars specified in ’set’ from the beginning and the end of string s1.
// Allocates and returns a copy of s1 modified.
char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int i;
	unsigned int end;
	size_t setlen;
	unsigned char trim_hashmap[256];

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
	return(ft_substr(s1, i, end - i + 1));
}

int		ft_token_count(char const *str, char c)
{
	int tok;
	int i;

	tok = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c && i > 0 && str[i - 1] != c)
			tok++;
		i++;
	}
	if (i > 0 && str[i] == '\0' && str[i - 1] != c)
		tok++;
	return (tok);
}

void	ft_split_tokens(char *scopy, char c, char ***result)
{
	int i;
	int tok;
	int end;
	int i_next;

	i_next = 0;
	i = 0;
	tok = 0;
	while (scopy[i])
	{
		end = i + 1;
		while (scopy[end] != c && scopy[end] != '\0')
			end++;
		if (!scopy[end])
			i_next = end;
		else
			i_next = end + 1;
		scopy[end] = '\0';
		(*result)[tok++] = ft_strdup(&scopy[i]);
		while (scopy[i_next] == c)
			i_next++;
		i = i_next;
	}
}

// Splits ’s’ using the character ’c’ as a delimiter.
// Allocates and returns an array of strings obtained.
char	**ft_split(char const *s, char c)
{
	char	*scopy;
	char	**result;
	int		counttok;
	char	set[2];

	if (!s)
		return (NULL);
	set[0] = c;
	set[1] = '\0';
	scopy = ft_strtrim(s, set);
	counttok = ft_token_count(s, c);
	if (!(result = (char **)malloc((counttok + 1) * sizeof(char *))))
		return (NULL);
	result[counttok] = NULL;
	ft_split_tokens(scopy, c, &result);
	free((void *)scopy);
	return (result);
}

int main()
{
    int i = 0;
	char **result;
	char *s = "      My plant has   just grown a new leaf  ";
	char c = ' ';
	result = ft_split(s, c);

	while (result[i])
		printf("[%s]\n", result[i++]);

	return 0;
}
