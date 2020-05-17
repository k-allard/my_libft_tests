/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:21:57 by kallard           #+#    #+#             */
/*   Updated: 2020/05/17 18:21:58 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <string.h>   //uncomment and change "ft_strlcat" -> "strlcat" in main() 
                        //to check the original function's output

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

// Adds the src string --> to the dest string
// Overwrites the terminating null byte at the end of dest
// Guarantees to NUL-terminate the result
size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t i;
	size_t src_len;
	size_t dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dest_len >= destsize)
		return (destsize + src_len);
	while (src[i] && dest_len + i < destsize - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

int main()
{  
    size_t  sz;
    char   *str =    "houston no problems here";
    char  buf1[22] = "XXXXXXXXX";                     
    char  buf2[26];
    char  buf3[4] = "XXX";

    sz = ft_strlcat(buf1, str, sizeof(buf1));    
    printf("After :  \"%s\"\n\n", buf1);

    sz = ft_strlcat(buf2, str, sizeof(buf2));    
    printf("After :  \"%s\"\n\n", buf2);

    sz = ft_strlcat(buf3, str, sizeof(buf3));    
    printf("After :  \"%s\"\n\n", buf3);

    return 0;
}