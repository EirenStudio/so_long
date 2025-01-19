/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:16:15 by jenbeita          #+#    #+#             */
/*   Updated: 2024/09/30 16:16:16 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_printchecker(char type, va_list arg)
{
	if (type == 'c')
		return (ft_print_char((char)va_arg(arg, int)));
	else if (type == 's')
		return (ft_print_str((char *)va_arg(arg, int *)));
	else if (type == 'p')
		return (ft_print_ptr(va_arg(arg, void *)));
	else if (type == 'd')
		return (ft_print_int(va_arg(arg, int)));
	else if (type == 'i')
		return (ft_print_int(va_arg(arg, int)));
	else if (type == 'u')
		return (ft_print_uint(va_arg(arg, unsigned int)));
	else if (type == 'x')
		return (ft_print_hex(va_arg(arg, unsigned int), 1));
	else if (type == 'X')
		return (ft_print_hex(va_arg(arg, unsigned int), 0));
	else if (type == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int				print_ln;
	unsigned int	i;
	va_list			arg;

	i = 0;
	print_ln = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			print_ln += ft_printchecker(str[i], arg);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
			print_ln++;
		}
	}
	va_end(arg);
	return (print_ln);
}
