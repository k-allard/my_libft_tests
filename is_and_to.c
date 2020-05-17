/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_and_to.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:20:47 by kallard           #+#    #+#             */
/*   Updated: 2020/05/17 18:20:48 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_toupper(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (ch - 32);
	return (ch);
}

int	ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (ch + 32);
	return (ch);
}

// Checks whether ch is either a decimal digit or a letter.
int	ft_isalnum(int ch)
{
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')
		|| (ch >= '0' && ch <= '9'))
		return (1);
	return (0);
}

// Checks whether ch is either an uppercase or lowercase letter.
int	ft_isalpha(int ch)
{
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		return (1);
	return (0);
}

// Checks whether ch is an ASCII character.
int	ft_isascii(int ch)
{
	if (ch >= 0 && ch <= 127)
		return (1);
	return (0);
}

// Checks whether ch is a digit.
int	ft_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

// Checks whether ch is a printable character.
int	ft_isprint(int ch)
{
	if (ch >= 32 && ch <= 126)
		return (1);
	return (0);
}

int main()
{
	char ch;

	printf("Enter your char:\n");
	fflush(stdin);
	scanf("%c", &ch);
	while (ch != 'Q')
	{
		ft_isascii(ch) ? printf("\x1b[1;32m+ ASCII character.\x1b[0m\n") : printf("\x1b[1;31m— Not an ASCII character.\x1b[0m\n");
		ft_isprint(ch) ? printf("\x1b[1;32m+ Printable.\x1b[0m\n") : printf("\x1b[1;31m— Not printable.\x1b[0m\n");
		ft_isalnum(ch) ? printf("\x1b[1;32m+ Alphanumeric.\x1b[0m\n") : printf("\x1b[1;31m— Not alphanumeric.\x1b[0m\n");
		ft_isdigit(ch) ? printf("\x1b[1;32m+ Digit.\x1b[0m\n") : printf("\x1b[1;31m— Not a digit.\x1b[0m\n");

		if (ft_isalpha(ch)) 
		{
			printf("\x1b[1;32m+ Letter.\x1b[0m\n");
			if (ch >= 'a' && ch <= 'z')
				printf("\x1b[2mConverting to uppercase. . .\x1b[0m\n%c\n", ft_toupper(ch));
			else
				printf("\x1b[2mConverting to lowercase. . .\x1b[0m\n%c\n", ft_tolower(ch));
		}
		else
			printf("\x1b[1;31m— Not a letter.\x1b[0m\n");

		printf("Enter another char or \x1b[1mQ\x1b[0m to exit:\n");
		fflush(stdin);
		scanf("%c", &ch);
	}
	return 0;
}
