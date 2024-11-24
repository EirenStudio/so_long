/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:55:41 by jenbeita          #+#    #+#             */
/*   Updated: 2024/09/13 13:55:42 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charchecker(const char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	size_t	i;
	size_t	n;
	size_t	k;

	if (!s1 || !set)
		return (NULL);
	n = 0;
	while (s1[n] && ft_charchecker(s1[n], set))
		n++;
	k = ft_strlen(s1);
	while (k > n && ft_charchecker(s1[k - 1], set))
		k--;
	str = (char *)malloc(sizeof(*s1) * (k - n + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (n < k)
		str[i++] = s1[n++];
	str[i] = 0;
	return (str);
}
