/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:54:59 by mel-hajj          #+#    #+#             */
/*   Updated: 2024/11/11 14:36:42 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*start;
	const char	*end;
	size_t		len;
	char		*x;

	if (!s1)
		return (NULL);
	start = s1;
	end = s1 + ft_strlen(s1) - 1;
	while (start <= end && ft_strchr(set, *start))
		start++;
	while (end >= start && ft_strchr(set, *end))
		end--;
	len = end - start + 1;
	x = malloc(len + 1);
	if (!x)
		return (0);
	ft_memcpy(x, start, len);
	x[len] = '\0';
	return (x);
}
