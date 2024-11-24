/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:45:48 by jenbeita          #+#    #+#             */
/*   Updated: 2024/09/11 21:45:49 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if ((!needle || !haystack) && len == 0)
		return (NULL);
	if (*needle == '\0')
		return ((char *) haystack);
	while (haystack[i] != '\0' && i < len)
	{
		k = 0;
		while (needle[k] != '\0'
			&& haystack[i + k] == needle[k] && (i + k) < len)
			k++;
		if (needle[k] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
