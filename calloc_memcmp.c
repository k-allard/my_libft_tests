/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc_memcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:20:42 by kallard           #+#    #+#             */
/*   Updated: 2020/05/17 18:20:43 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> 

// Compares byte strings, both assumed to be n bytes long. 
// Returns zero if they are identical.
int	ft_memcmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((i < n) && ((unsigned char *)str1)[i] == ((unsigned char *)str2)[i])
		i++;
	if (i == n)
		return (0);
	else
		return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
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

int main()
{
    char *dest;
	int i;

	dest = ft_calloc(5, sizeof(char));
    if (!dest) 
	{
		printf("Memory allocation failed!");
		return 0;
	}

	char array0[] = {'\0', '\0', '\0', '\0', '\0'};
	//memcmp will compare dest string with 5 zeros
	i = ft_memcmp(dest, array0, 5);
	if (!i)
	{
		printf("Memory successfully allocated!");
		printf("\nDest string is: \"%s\"\n", dest);
		printf("Dest string adress: %p", dest);
	}
	else 
		printf("Ft_calloc() ERROR");
	return 0;
}
