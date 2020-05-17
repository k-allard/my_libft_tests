/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:22:04 by kallard           #+#    #+#             */
/*   Updated: 2020/05/17 18:22:05 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

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

int main()
{
    char *str = "my plant has just grown a new leaf";
	printf ("String \"%s\"\nLength: %zu (my function) / %zu (original fucntion).", str, ft_strlen(str), strlen(str));
	return 0;
}
