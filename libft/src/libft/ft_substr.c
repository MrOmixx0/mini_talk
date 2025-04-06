/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:19:16 by mel-hajj          #+#    #+#             */
/*   Updated: 2024/11/11 14:34:05 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*x;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	x = malloc(len + 1);
	if (!x)
		return (0);
	while (len > 0 && s[start] != '\0')
	{
		x[i] = s[start];
		start++;
		i++;
		len--;
	}
	x[i] = '\0';
	return (x);
}
