/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:49:43 by jenbeita          #+#    #+#             */
/*   Updated: 2024/09/13 12:49:45 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*res;

	res = malloc(num * size);
	if (res == NULL)
		return (NULL);
	ft_memset(res, 0, num * size);
	return (res);
}
