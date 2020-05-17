/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:21:24 by kallard           #+#    #+#             */
/*   Updated: 2020/05/17 18:21:25 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Copies bytes from string src --> to non-overlapping string dst.  
// If the char c occurs in src, the copy stops.
// Returns a pointer to the byte after the copy of c in dst.  
// Otherwise, copies n bytes and returns NULL.
void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*dest_p;
	unsigned char	*src_p;

	if (!src && !dest)
		return (0);
	dest_p = (unsigned char *)dest;
	src_p = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_p[i] = src_p[i];
		if (src_p[i] == (unsigned char)(c))
			return ((void *)(dest + i + 1));
		i++;
	}
	return (NULL);
}

int main()
{
    char dest1[8] = "12345ss";
    char src1[6] = "65432";
    ft_memccpy(dest1, src1, '3', 8);

    char dest2[8] = "12345ss";
    char src2[6] = "65432";
    memccpy(dest2, src2, '3', 8);
    
    if (!memcmp(dest1, dest2, 8))
        printf("\x1b[1;32mIt works!\x1b[0m\nBoth dest strings are [%s]\n", dest1);
    else
    {
        printf("\x1b[1;31mYour ft_memccpy doesn't work correctly.\x1b[0m\n");
        printf("Your dest string is [%s].\nOriginal memccpy's dest is [%s]\n", dest1, dest2);
    }
    return 0;
}
