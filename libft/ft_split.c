/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:10:47 by jenbeita          #+#    #+#             */
/*   Updated: 2024/09/13 14:10:48 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char delim)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == delim)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != delim)
			i++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	dup = (char *)malloc(n + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(const char *s, char delim)
{
	char	**result;
	int		words;
	int		i[3];

	if (!s)
		return (NULL);
	words = ft_count_words(s, delim);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	while (s[i[0]])
	{
		while (s[i[0]] == delim)
			i[0]++;
		i[2] = i[0];
		while (s[i[0]] && s[i[0]] != delim)
			i[0]++;
		if (i[0] > i[2])
			result[i[1]++] = ft_strndup(s + i[2], i[0] - i[2]);
	}
	result[i[1]] = NULL;
	return (result);
}
