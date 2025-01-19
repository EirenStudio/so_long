/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <josuenbeita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:58:06 by jenbeita          #+#    #+#             */
/*   Updated: 2025/01/18 11:08:48 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapcheck(t_map *map, int x, int y, int fd)
{
	int	playernum;
	int	exitnum;

	playernum = 0;
	exitnum = 0;
	while (y)
	{
		x = map->size[0] - 1;
		while (x)
		{
			if (map->element[x][y] == 'P')
				playernum++;
			else if (map->element[x][y] == 'E')
				exitnum++;
			else if (map->element[x][y] != '1' && map->element[x][y] != '0'
				&& map->element[x][y] != 'C' && map->element[x][y] != '\n')
				errorexit("Error: Invalid Map Format.\n", map, NULL, 0);
			x--;
		}
		y--;
	}
	if (playernum != 1)
		errorexit("Error: The Character must be Once.\n", map, NULL, fd);
	if (exitnum != 1)
		errorexit("Error: The Exit must be Once.\n", map, NULL, fd);
}

void	mapmount(t_map *map)
{
	map->window = NULL;
	map->imgs = NULL;
	map->mlx = NULL;
	map->size[0] = 0;
}
