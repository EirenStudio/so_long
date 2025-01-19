/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:48:24 by jenbeita          #+#    #+#             */
/*   Updated: 2024/09/11 16:48:26 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *inp, const void *valor, size_t bytes)
{
	size_t						i;
	unsigned char				*ninp;
	const unsigned char			*nval;

	if (bytes == 0 || inp == valor)
		return (inp);
	i = 0;
	ninp = (unsigned char *) inp;
	nval = (const unsigned char *) valor;
	while (i < bytes)
	{
		ninp[i] = nval[i];
		i++;
	}
	return (ninp);
}
