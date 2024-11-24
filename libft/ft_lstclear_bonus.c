/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:18:57 by jenbeita          #+#    #+#             */
/*   Updated: 2024/09/18 09:18:59 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;
	t_list	*k;

	if (lst && *lst && del)
	{
		k = (t_list *)*lst;
		while (k)
		{
			list = k->next;
			ft_lstdelone(k, del);
			k = list;
		}
		*lst = NULL;
	}
}
