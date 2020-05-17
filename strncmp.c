/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:22:09 by kallard           #+#    #+#             */
/*   Updated: 2020/05/17 18:22:10 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h> 

// Compares not more than n chars from strings s1 and s2.
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] && s2[i] && i < n - 1 && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int main() 
{ 
    char str[] = "str1Function"; 
    char str2[] = "str2Function"; 
    int p; 
	int ft;  

    p = strncmp(str, str2, 4); 
    ft = ft_strncmp(str, str2, 4); 

	if (p == ft)
	{
		printf("Ft_function output == original function output!\n");
		if (p) 
		{ 
			printf("Diff char found!\n"); 
			p > 0 ? printf("s1 > s2") : printf("s1 < s2"); 
		} 
		else
			printf("Strings are equal!\n"); 
	}
	else 
		printf("ERROR\nft_function != original\n");
    return 0; 
} 
