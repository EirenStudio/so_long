/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <josuenbeita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:25:11 by jenbeita          #+#    #+#             */
/*   Updated: 2025/01/18 11:04:34 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_map
{
	int		size[2];
	int		element[256][256];
	void	*window;
	void	*mlx;
	int		pos[2];
	int		coins;
	int		movements;
	void	**imgs;

}	t_map;

int		moveplayer(int dir, t_map *map);
void	errorexit(char *errormsg, t_map *map, char *line, int fd);
int		closewindow(t_map *map);
void	winwin(t_map *map);
void	die(t_map *map);
void	freeimgs(void *mlx, void **imgs);

void	putplayer(t_map *map, void *window, int x, int y);
void	putcoin(t_map *map, int x, int y);
void	loadmap(t_map *map, int x, int y);
void	freemap(t_map *map);

void	mapcheck(t_map *map, int x, int y, int fd);
void	mapmount(t_map *map);

#endif