/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:00:32 by mel-hajj          #+#    #+#             */
/*   Updated: 2024/11/12 10:10:28 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*x;

	x = s;
	i = 0;
	while (i < n)
	{
		x[i] = c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>

int main ()
{
	int s[10];
	//ft_memset(s, , 3);
	//ft_memset(s, 1, 2);
	ft_memset(s, 1300, 1);
	printf("%d",s[0]);
}*/
