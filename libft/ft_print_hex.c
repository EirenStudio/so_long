/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:15:25 by jenbeita          #+#    #+#             */
/*   Updated: 2024/09/30 16:15:26 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex(unsigned int n, int minus)
{
	char	*hex;
	int		size;

	size = 0;
	hex = "0123456789abcdef";
	if (minus == 0)
		hex = "0123456789ABCDEF";
	if (n < 16)
	{
		size += ft_print_char(hex[n]);
	}
	else
	{
		size += ft_print_hex(n / 16, minus);
		size += ft_print_hex(n % 16, minus);
	}
	return (size);
}
