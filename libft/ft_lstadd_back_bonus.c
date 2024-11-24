/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:16:47 by jenbeita          #+#    #+#             */
/*   Updated: 2024/09/18 09:16:48 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *elm)
{
	t_list	*list;

	if (!lst || !elm)
		return ;
	if (!(*lst))
		*lst = elm;
	else
	{
		list = *lst;
		while (list->next)
			list = list->next;
		list->next = elm;
	}
}
