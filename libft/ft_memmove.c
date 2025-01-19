/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:52:31 by jenbeita          #+#    #+#             */
/*   Updated: 2024/09/11 18:52:33 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *inp, const void *val, size_t bytes)
{
	unsigned char		*ninp;
	unsigned const char	*nval;

	if (inp < val)
		return (ft_memcpy(inp, val, bytes));
	ninp = (unsigned char *) inp;
	nval = (unsigned const char *) val;
	if (!bytes || inp == val)
		return (inp);
	while (bytes--)
		ninp[bytes] = nval[bytes];
	return (inp);
}
