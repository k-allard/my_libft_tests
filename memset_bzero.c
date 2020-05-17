/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset_bzero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:21:45 by kallard           #+#    #+#             */
/*   Updated: 2020/05/17 18:21:46 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <stdlib.h>
#include <strings.h> 

// to print char strings
void printArray(char arr[], int n) 
{ 
    for (int i=0; i<n; i++) 
        printf("%c ", arr[i]); 
    printf("\n");
} 

// to print int arrays
void printArray2(int arr[], int n) 
{ 
   for (int i=0; i<n; i++) 
        printf("%d ", arr[i]);
    printf("\n");
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

int main() 
{ 
    char arr1[20] = "HelloWorld!";
    printf("Char string 1: "); 
    printArray(arr1, 10); 
    memset(arr1, 'x', 5); 
    printf("Array 1 after memset(): "); 
    printArray(arr1, 10); 

    char arr3[20] = "HelloWorld!";
    ft_memset(arr3, 'x', 5);
    printf("Array 1 after ft_memset(): "); 
    printArray(arr3, 10);

    printf("____________________________\n");

    int arr2[5] = {1,2,3,4,5};
    printf("Int array 2: "); 
    printArray2(arr2, 5); 
    
    int arr7[5] = {1,2,3,4,5};
    bzero(arr7, 8);
    printf("Array 2 after bzero(): ");
    printArray2(arr7, 5); 

    int arr8[5] = {1,2,3,4,5};
    ft_bzero(arr8, 8);
    printf("Array 2 after ft_bzero(): ");
    printArray2(arr8, 5);

    return 0;
} 
