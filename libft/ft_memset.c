/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:36:48 by jenbeita          #+#    #+#             */
/*   Updated: 2024/09/09 17:36:51 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *inp, int val, size_t bytes)
{
	size_t		i;
	char		*tmp;

	i = 0;
	tmp = (char *) inp;
	while (i < bytes)
	{
		tmp[i] = (unsigned char)val;
		i++;
	}
	return (inp);
}
