/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:25:38 by jenbeita          #+#    #+#             */
/*   Updated: 2024/09/09 17:25:43 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *inp, size_t bytes)
{
	int		i;
	char	*res;

	res = (char *) inp;
	i = 0;
	while (i < (int)bytes)
	{
		res[i] = '\0';
		i++;
	}
}
