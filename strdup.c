/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:21:53 by kallard           #+#    #+#             */
/*   Updated: 2020/05/17 18:21:54 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> 

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

int main()
{
    char src[] = "42 strdup function";
    char *dest;
	printf("Src string is: \"%s\"\n", src);
    printf("Src string adress: %p", src);
    printf("\n\nDuplicating . . .\n");
    dest = ft_strdup(src);
    printf("\nDest string is: \"%s\"\n", dest);
	printf("Dest string adress: %p", dest);
	return 0;
}
