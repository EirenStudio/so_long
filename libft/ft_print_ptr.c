/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:15:50 by jenbeita          #+#    #+#             */
/*   Updated: 2024/09/30 16:15:52 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	setptr(unsigned long addr)
{
	char	*hex_digits;
	char	buffer[16];
	int		size;
	int		i;

	hex_digits = "0123456789abcdef";
	i = 0;
	size = 0;
	if (addr == 0)
		size += ft_print_char('0');
	while (addr > 0)
	{
		buffer[i++] = hex_digits[addr % 16];
		addr /= 16;
	}
	while (--i >= 0)
	{
		ft_print_char(buffer[i]);
		size++;
	}
	return (size);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long	addr;
	int				size;

	addr = (unsigned long)ptr;
	if (addr == 0)
		return (ft_print_str("(nil)"));
	ft_print_char('0');
	ft_print_char('x');
	size = 2;
	size += setptr(addr);
	return (size);
}
