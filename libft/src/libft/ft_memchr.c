/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:19:56 by mel-hajj          #+#    #+#             */
/*   Updated: 2024/11/12 11:36:18 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*x;

	x = s;
	while (n > 0)
	{
		if (*x == (unsigned char)c)
			return ((void *)x);
		x++;
		n--;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main ()
{
	char s[] = "hello world !";
//	char *x = ft_memchr(s, 'o', 3);
	char *k = memchr(s, 'o', 3);
//	printf("%s\n",x);
	printf("%s\n",k);
}*/
