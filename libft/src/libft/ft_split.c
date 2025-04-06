/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:27:23 by mel-hajj          #+#    #+#             */
/*   Updated: 2024/11/15 20:36:15 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *str, char c)
{
	int	i;
	int	p;

	i = 0;
	p = 1;
	while (*str)
	{
		if (p == 1 && *str != c)
		{
			p = 0;
			i++;
		}
		if (*str == c)
			p = 1;
		str++;
	}
	return (i);
}

static size_t	ft_word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	ft_free_split(char **x, size_t i)
{
	while (i > 0)
		free(x[--i]);
	free(x);
}

static char	*ft_strndup(char const *s, size_t n)
{
	char	*str;
	size_t	i;

	str = malloc(n + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char		**x;
	int			words;
	int			i;
	int			len;

	if (!s)
		return (NULL);
	words = ft_count(s, c);
	x = malloc(sizeof(char *) * (words + 1));
	if (!x)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		len = ft_word_len(s, c);
		x[i] = ft_strndup(s, len);
		if (!x[i])
			return (ft_free_split(x, i), NULL);
		s += len;
		i++;
	}
	x[i] = (NULL);
	return (x);
}
/*
#include <stdio.h>
int main ()
{
	char x[] = "HELLO ALL OF YOU ARE YOU GOOD ?";
	char **res = ft_split(x,' ');
	int i = 0;
	int words = ft_count(x, ' ');
	printf ("%d\n", words);
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
ft_free_split(res,i);
}*/
