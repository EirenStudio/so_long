/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:32:54 by jenbeita          #+#    #+#             */
/*   Updated: 2024/09/11 21:32:56 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *) ptr;
	i = 0;
	while (i < num)
	{
		if (p[i] == (unsigned char) value)
			return ((void *)&p[i]);
		i++;
	}
	return (NULL);
}
