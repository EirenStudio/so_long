/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:15:32 by jenbeita          #+#    #+#             */
/*   Updated: 2024/09/30 16:15:35 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_int(int num)
{
	int		size;
	char	*str;

	str = ft_itoa(num);
	size = ft_print_str(str);
	free(str);
	return (size);
}
