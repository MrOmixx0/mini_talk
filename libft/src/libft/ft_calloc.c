/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:02:22 by mel-hajj          #+#    #+#             */
/*   Updated: 2024/11/11 18:34:56 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*x;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	x = malloc(nmemb * size);
	if (!x)
		return (NULL);
	ft_bzero(x, nmemb * size);
	return (x);
}
/*
#include <stdio.h>

int main ()
{
	//printf("%s\n", ft_calloc(11550000,5151));
	printf("%s\n", calloc(11550000,5151));

}*/
