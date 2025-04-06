/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:31:36 by mel-hajj          #+#    #+#             */
/*   Updated: 2024/11/12 14:43:15 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_min_case(void)
{
	return (ft_strdup("-2147483648"));
}

char	*ft_itoa(int n)
{
	char	*x;
	size_t	len_n;
	size_t	i;

	i = 0;
	len_n = ft_count_len(n);
	if (n == -2147483648)
		return (ft_min_case());
	x = malloc(len_n + 1);
	if (!x)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		x[0] = '-';
		i++;
	}
	x[len_n] = '\0';
	while (len_n > i)
	{
		x[--len_n] = (n % 10) + '0';
		n /= 10;
	}
	return (x);
}
/*
#include <stdio.h>

int main ()
{
	printf ("%s\n", ft_itoa(-154510526));
}*/
