/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:55:17 by mel-hajj          #+#    #+#             */
/*   Updated: 2024/12/19 18:43:16 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checker(const char *s, va_list ag)
{
	if (*s == 'c')
		return (ft_putchar(va_arg(ag, int)));
	if (*s == 's')
		return (ft_putstr(va_arg(ag, char *)));
	if (*s == 'p')
		return (ft_pointer(va_arg(ag, unsigned long)));
	if (*s == 'i' || *s == 'd')
		return (ft_putnbr(va_arg(ag, int)));
	if (*s == 'u' || *s == 'x' || *s == 'X' )
		return (ft_putuxx(va_arg(ag, unsigned int), *s));
	if (*s == '%')
		return (ft_putchar('%'));
	ft_putchar('%');
	ft_putchar(*s);
	return (2);
}

int	ft_printf(const char *s, ...)
{
	va_list	ag;
	int		count;

	if (!s)
		return (-1);
	count = 0;
	va_start(ag, s);
	while (*s)
	{
		if (*s == '%')
			count += checker(++s, ag);
		else
			count += ft_putchar(*s);
		s++;
	}
	va_end(ag);
	return (count);
}
