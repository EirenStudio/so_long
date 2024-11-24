/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:15:42 by jenbeita          #+#    #+#             */
/*   Updated: 2024/09/30 16:15:43 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_uint(unsigned int n)
{
	char	buffer[10];
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (n == 0)
		return (ft_print_char('0'));
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (--i >= 0)
		size += ft_print_char(buffer[i]);
	return (size);
}
