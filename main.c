/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <josuenbeita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:18:05 by jenbeita          #+#    #+#             */
/*   Updated: 2025/01/18 11:06:54 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	inputcheck(int inpcount, char **inp)
{
	int	fd;

	if (inpcount != 2)
		errorexit("Error: Map not specified\n", NULL, NULL, 0);
	fd = open(inp[1], O_RDONLY);
	if (fd == -1)
		errorexit("Error: Invalid map\n", NULL, NULL, 0);
	if (ft_strnstr(inp[1], ".ber", ft_strlen(inp[1])) == NULL)
		errorexit("Error: Invalid map extension\n", NULL, NULL, fd);
	return (fd);
}

void	loadwindow(t_map *map, int fd, int x, int y)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		x = 0;
		while (line[x] != '\n' && line[x] != '\0')
		{
			if (x > 255 || y > 255)
				errorexit("Error: Too Big Map.\n", map, line, fd);
			if (x >= map->size[0] && map->size[0] != 0)
				errorexit("Error: Invalid Map Format.\n", map, line, fd);
			map->element[x][y] = line[x];
			x++;
		}
		if (map->size[0] != 0 && map->size[0] != x)
			errorexit("Error: Invalid Map Format.\n", map, line, fd);
		map->size[0] = x;
		y++;
		free(line);
		line = get_next_line(fd);
	}
	map->size[1] = y;
	mapcheck(map, x, y - 1, fd);
	close(fd);
}

void	**loadimgs(void *mlx)
{
	void	**imgs;
	int		size;

	imgs = malloc(5 * sizeof(void *));
	if (!imgs)
		return (NULL);
	size = 32;
	imgs[0] = mlx_xpm_file_to_image(mlx,
			"./textures/floor.xpm", &size, &size);
	imgs[1] = mlx_xpm_file_to_image(mlx,
			"./textures/player.xpm", &size, &size);
	imgs[2] = mlx_xpm_file_to_image(mlx,
			"./textures/coin.xpm", &size, &size);
	imgs[3] = mlx_xpm_file_to_image(mlx,
			"./textures/exit.xpm", &size, &size);
	imgs[4] = mlx_xpm_file_to_image(mlx,
			"./textures/brick.xpm", &size, &size);
	if (!imgs[0] || !imgs[1] || !imgs[2] || !imgs[3] || !imgs[4])
		return (NULL);
	return (imgs);
}

int	getbutton(int btn, t_map *map)
{
	if (btn == 65307)
		closewindow(map);
	else if (btn == 119 || btn == 65362)
		moveplayer(0, map);
	else if (btn == 115 || btn == 65364)
		moveplayer(1, map);
	else if (btn == 97 || btn == 65361)
		moveplayer(2, map);
	else if (btn == 100 || btn == 65363)
		moveplayer(3, map);
	return (0);
}

int	main(int inpcount, char **inp)
{
	int		fd;
	t_map	map;
	int		x;
	int		y;

	x = 0;
	y = 0;
	mapmount(&map);
	fd = inputcheck(inpcount, inp);
	map.mlx = mlx_init();
	if (!map.mlx)
		errorexit("Error: Initialization failed.\n", &map, NULL, fd);
	map.imgs = loadimgs(map.mlx);
	if (!map.imgs)
		errorexit("Error: Initialization failed.\n", &map, NULL, fd);
	loadwindow(&map, fd, x, y);
	map.window = mlx_new_window(map.mlx, map.size[0] * 32,
			map.size[1] * 32, "so_long");
	if (!map.window)
		errorexit("Error: Initialization failed.\n", &map, NULL, 0);
	loadmap(&map, x, y);
	mlx_hook(map.window, 17, 1L << 2, closewindow, &map);
	mlx_key_hook(map.window, getbutton, &map);
	mlx_loop(map.mlx);
	return (1);
}
