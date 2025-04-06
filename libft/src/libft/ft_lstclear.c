/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:37:24 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/07 00:37:26 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*previous;

	current = (*lst);
	if (lst && del)
	{
		while (current != NULL)
		{
			previous = current;
			del((*current).content);
			current = (*current).next;
			free(previous);
		}
		(*lst) = NULL;
	}
}
