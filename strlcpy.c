/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:22:00 by kallard           #+#    #+#             */
/*   Updated: 2020/05/17 18:22:01 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

// Copies up to dstsize - 1 characters from the string src --> to dest,
// NUL-terminates the result.
size_t ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t i;

	i = 0;
	if (!dest)
		return (0);
	if (destsize > 0)
	{
		while (src[i] && i < destsize - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

int main()
{  
    size_t  sz;
    char   *str =    "houston no problems here";
    char  buf1[19] = "XXXXXXXXXXXXXXXXXX";                     
    char  buf2[25] = "XXXXXXXXXXXXXXXXXXXXXXXX";
    char  buf3[35] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";

    printf("Before:  \"%s\"\n", buf1);
    sz = ft_strlcpy(buf1, str, sizeof(buf1));    
    printf("After copying :  \"%s\"\n", buf1);
    if (sz >= sizeof(buf1))   
        printf("Str has been truncated from %zu to %lu symbols!\n\n", sz, sizeof(buf1)-1);

    printf("Before:  \"%s\"\n", buf2);
    sz = ft_strlcpy(buf2, str, sizeof(buf2));
    printf("After copying :  \"%s\"\n", buf2);
    if (sz >= sizeof(buf2))   
        printf("Str has been truncated from %zu to %lu symbols!\n\n", sz, sizeof(buf2)-1);

    printf("\nBefore:  \"%s\"\n", buf3);
    sz = ft_strlcpy(buf3, str, sizeof(buf3));    
    printf("After copying :  \"%s\"\n", buf3);
    if (sz >= sizeof(buf3))   
        printf("Str has been truncated from %zu to %lu symbols!\n\n", sz, sizeof(buf3)-1);

    return 0;
}
