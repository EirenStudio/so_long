/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <josuenbeita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:36:53 by jenbeita          #+#    #+#             */
/*   Updated: 2025/01/11 10:51:25 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errorexit(char *errormsg, t_map *map, char *line, int fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (fd)
		close(fd);
	freemap(map);
	perror(errormsg);
	exit(EXIT_FAILURE);
}

int	closewindow(t_map *map)
{
	freemap(map);
	exit(EXIT_SUCCESS);
	return (0);
}

void	winwin(t_map *map)
{
	ft_printf("YOU WIN!\n");
	closewindow(map);
}

void	die(t_map *map)
{
	ft_printf("Game Over!\n");
	closewindow(map);
}
