/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:52:39 by jenbeita          #+#    #+#             */
/*   Updated: 2024/09/13 13:52:41 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	int		i[4];

	if (!s1 || !s2)
		return (NULL);
	i[0] = ft_strlen(s1);
	i[1] = ft_strlen(s2);
	res = (char *) malloc(i[0] + i[1] + 1);
	i[2] = 0;
	i[3] = 0;
	if (res == NULL)
		return (NULL);
	while (i[3] < i[0] + i[1])
	{
		if (i[3] < i[0])
			res[i[3]] = s1[i[3]];
		else
		{
			res[i[3]] = s2[i[2]];
			i[2]++;
		}
		i[3]++;
	}
	res[i[3]] = '\0';
	return (res);
}
