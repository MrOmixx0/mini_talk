/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:07:47 by mel-hajj          #+#    #+#             */
/*   Updated: 2024/11/11 14:42:53 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	size_t	len_s;
	size_t	i;
	char	*x;

	if (!s || !f)
		return (NULL);
	len_s = ft_strlen(s);
	x = malloc(len_s + 1);
	i = 0;
	if (!x)
		return (NULL);
	while (s[i])
	{
		x[i] = f(i, s[i]);
		i++;
	}
	x[i] = '\0';
	return (x);
}
