/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:21:43 by kallard           #+#    #+#             */
/*   Updated: 2020/05/17 18:21:44 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	*ft_memcpy_rev(void *restrict dest, const void *restrict src, size_t n)
{
	if (!src && !dest)
		return (0);
	while (n--)
	{
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	return (dest);
}

// Copies n bytes from memory area src --> to non-overlapping area dst.
void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	unsigned int i;

	i = 0;
	if (!src && !dest)
		return (0);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

// Copies len bytes from string src --> to string dest.
// The two strings may overlap.
void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (dest < src)
		return (ft_memcpy(dest, src, len));
	if (dest > src)
		return (ft_memcpy_rev(dest, src, len));
	return (dest);
}

int main()
{
    char str[] = "GOOD  JOB";
    printf("%s\n   |  \n   V  \n", str);
    ft_memmove(str + 1, str, 4 * sizeof(char)); //change to memmove() to see the original function's output
    printf("%s\t— (copied with overlaping)", str);
    ft_memcpy(str + 1, str + 5, 4 * sizeof(char));
    printf("\n   |  \n   V  \n%s\t— (copied without overlaping)\n", str);
    return 0;
}
