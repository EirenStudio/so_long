/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:20:35 by jenbeita          #+#    #+#             */
/*   Updated: 2024/09/18 09:20:37 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*item;

	if (!lst || !f)
		return (NULL);
	item = ft_lstnew(f(lst->content));
	if (!item)
		return (NULL);
	list = item;
	lst = lst->next;
	while (lst)
	{
		item = ft_lstnew(f(lst->content));
		if (!item)
		{
			ft_lstclear(&list, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&list, item);
	}
	return (list);
}
