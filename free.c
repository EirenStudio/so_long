/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <josuenbeita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:51:50 by jenbeita          #+#    #+#             */
/*   Updated: 2025/01/10 16:12:08 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freemap(t_map *map)
{
	if (map)
	{
		if (map->imgs)
			freeimgs(map->mlx, map->imgs);
		if (map->window)
		{
			mlx_destroy_window(map->mlx, map->window);
		}
		if (map->mlx)
		{
			mlx_destroy_display(map->mlx);
			free(map->mlx);
		}
	}
}

void	freeimgs(void *mlx, void **imgs)
{
	if (imgs)
	{
		if (imgs[0])
			mlx_destroy_image(mlx, imgs[0]);
		if (imgs[1])
			mlx_destroy_image(mlx, imgs[1]);
		if (imgs[2])
			mlx_destroy_image(mlx, imgs[2]);
		if (imgs[3])
			mlx_destroy_image(mlx, imgs[3]);
		if (imgs[4])
			mlx_destroy_image(mlx, imgs[4]);
		free(imgs);
	}
}
