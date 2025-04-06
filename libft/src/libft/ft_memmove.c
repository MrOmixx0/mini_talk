/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:46:39 by mel-hajj          #+#    #+#             */
/*   Updated: 2024/11/15 20:23:08 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if ((src < dest) && (src + n > dest))
	{
		d = dest + n - 1;
		s = src + n - 1;
		while (n > 0)
		{
			*d = *s;
			d--;
			s--;
			n--;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main ()
{
	char s[] = "HELLO WORLD!";
	char x[] = "LEAGUE OF LEGENDS";
	ft_memmove((s + 2), s, 5);
	printf("%s\n", s);
	memmove((s + 2), s, 5);
	printf("%s\n", s);

}*/
