/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:53:06 by jenbeita          #+#    #+#             */
/*   Updated: 2024/09/13 12:53:08 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	int		size;
	int		i;

	size = ft_strlen(s) + 1;
	res = (char *)malloc(size);
	i = 0;
	if (res == NULL)
		return (NULL);
	while (i < size)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}
