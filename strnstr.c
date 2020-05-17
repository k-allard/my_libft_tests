/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:22:12 by kallard           #+#    #+#             */
/*   Updated: 2020/05/17 18:22:13 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h> 

// Locates the 1st occurrence of the string to_find in the string str, 
// where not more than len chars are searched.
char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t len2;

	if (to_find[0] == '\0')
		return ((char *)str);
	len2 = strlen(to_find);
	while (*str != '\0' && len >= len2)
	{
		if (*str == *to_find && memcmp(str, to_find, len2) == 0)
 			return ((char *)str);
		len--;
		str++;
	}
	return (0);
}

int main() 
{ 
    char str[] = "strFunction"; 
    char find[] = "Fun";
    char* p; 
  
    p = ft_strnstr(str, find, 6); 
  
    if (p) 
	{ 
        printf("String found\n"); 
        printf("Result string is '%s'", p); 
    } 
	else
        printf("String not found\n"); 
    return 0; 
} 
