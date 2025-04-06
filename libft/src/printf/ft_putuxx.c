/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:24:58 by mel-hajj          #+#    #+#             */
/*   Updated: 2024/12/19 17:22:58 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuxx(unsigned long n, char c)
{
	int				count;
	unsigned long	base;
	char			*xd;

	base = 16;
	xd = "0123456789abcdef";
	if (c == 'X')
		xd = "0123456789ABCDEF";
	if (c == 'u')
		base = 10;
	count = 0;
	if (n >= base)
		count += ft_putuxx((n / base), c);
	return (count + ft_putchar(xd[n % base]));
}
