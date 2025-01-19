/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putsprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <josuenbeita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:40:01 by jenbeita          #+#    #+#             */
/*   Updated: 2025/01/10 15:06:08 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	domove(t_map *map, int dir)
{
	if (dir == 0)
		map->pos[1]--;
	else if (dir == 1)
		map->pos[1]++;
	else if (dir == 2)
		map->pos[0]--;
	else if (dir == 3)
		map->pos[0]++;
	map->movements++;
	ft_printf("Movements: %d\n", map->movements);
	if (map->element[map->pos[0]][map->pos[1]] == 'C')
	{
		map->coins--;
		map->element[map->pos[0]][map->pos[1]] = '0';
	}
	if (map->element[map->pos[0]][map->pos[1]] == 'E')
	{
		if (map->coins == 0)
			winwin(map);
		else
			die(map);
	}
	return (1);
}

int	moveplayer(int dir, t_map *map)
{
	int	val;

	mlx_put_image_to_window(map->mlx, map->window,
		map->imgs[0], map->pos[0] * 32, map->pos[1] * 32);
	if (dir == 0 && map->element[map->pos[0]][map->pos[1] - 1] != '1'
		&& 0 < map->pos[1])
		val = domove(map, 0);
	else if (dir == 1 && map->element[map->pos[0]][map->pos[1] + 1] != '1'
		&& map->size[1] - 1 > map->pos[1])
		val = domove(map, 1);
	else if (dir == 2 && map->element[map->pos[0] - 1][map->pos[1]] != '1'
		&& 0 < map->pos[0])
		val = domove(map, 2);
	else if (dir == 3 && map->element[map->pos[0] + 1][map->pos[1]] != '1'
		&& map->size[0] - 1 > map->pos[0])
		val = domove(map, 3);
	mlx_put_image_to_window(map->mlx, map->window,
		map->imgs[1], map->pos[0] * 32, map->pos[1] * 32);
	return (val);
}

void	putplayer(t_map *map, void *window, int x, int y)
{
	mlx_put_image_to_window(map->mlx, window, map->imgs[1], x * 32, y * 32);
	map->pos[0] = x;
	map->pos[1] = y;
}

void	putcoin(t_map *map, int x, int y)
{
	mlx_put_image_to_window(map->mlx,
		map->window, map->imgs[2], x * 32, y * 32);
	map->coins++;
}

void	loadmap(t_map *map, int x, int y)
{
	y = 0;
	map->coins = 0;
	while (y <= map->size[1])
	{
		x = 0;
		while (x <= map->size[0])
		{
			mlx_put_image_to_window(map->mlx, map->window,
				map->imgs[0], x * 32, y * 32);
			if (map->element[x][y] == '1')
				mlx_put_image_to_window(map->mlx, map->window,
					map->imgs[4], x * 32, y * 32);
			if (map->element[x][y] == 'P')
				putplayer(map, map->window, x, y);
			if (map->element[x][y] == 'E')
				mlx_put_image_to_window(map->mlx, map->window,
					map->imgs[3], x * 32, y * 32);
			if (map->element[x][y] == 'C')
				putcoin(map, x, y);
			x++;
		}
		y++;
	}
}
