/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:52:07 by mel-hajj          #+#    #+#             */
/*   Updated: 2024/11/12 14:20:33 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	j;
	size_t	i;
	char	*x;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	x = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!x)
		return (0);
	while (i < ft_strlen(s1))
	{
		x[i] = s1[i];
		i++;
	}
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		x[i] = s2[j];
		i++;
		j++;
	}
	x[i] = '\0';
	return (x);
}
