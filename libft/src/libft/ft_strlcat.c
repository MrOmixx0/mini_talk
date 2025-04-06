/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:23:20 by mel-hajj          #+#    #+#             */
/*   Updated: 2024/11/01 21:25:09 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s;
	size_t	d;
	size_t	l;

	s = ft_strlen(src);
	if (!dst && size == 0)
		return (s);
	i = 0;
	d = ft_strlen(dst);
	l = s + d;
	if (size <= d)
		return (size + s);
	while (i < size - d - 1 && src[i] != '\0')
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (l);
}
