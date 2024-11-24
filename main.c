#include "so_long.h"

void errorexit(char *errormsg)
{
	perror(errormsg);
	exit(EXIT_FAILURE); 
}

int inputcheck(int inpcount, char **inp)
{
	int	fd;

	if(inpcount != 2)
		errorexit("Error: Map not specified");
	fd = open(inp[1], O_RDONLY);
	if (fd == -1)
		errorexit("Error: Invalid map");
	if (ft_strnstr(inp[1], ".ber", ft_strlen(inp[1])) == NULL)
		errorexit("Error: Invalid map extension");
	return (fd);
}
void loadmap(t_map *map, int fd, void *mlx)
{
	int		x;
	int		y;
	char	*line;
	
	x = 0;
	y = 0;
	line = get_next_line(fd);
	while(line)
	{
		x = 0;
		while(line[x] != '\n')
		{
			map->element[x][y] = line[x];
			x++;
		}
		y++;
		line = get_next_line(fd);
	}
	
	map->size[0] = x;
	map->size[1] = y;
	x = 0; 
	y = 0;
	mlx_new_window(mlx, map->size[0]*32, map->size[1]*32, "so_long");
	while (y <= map->size[0])
	{
		x = 0;
		while(x <= map->size[1])
		{
			ft_printf("%c", map->element[x][y]);
			if(map->element[x][y] == '0')
			{

			}
			if(map->element[x][y] == '1')
			{
				
			}
			if(map->element[x][y] == 'P')
			{
				
			}
			if(map->element[x][y] == 'E')
			{
				
			}
			if(map->element[x][y] == 'C')
			{
				
			}
			x++;
		}
			ft_printf("\n");
		y++;
	}
}

int	main(int inpcount, char **inp)
{
	int		fd;
	t_map	map;
	void	*mlx;

	fd = inputcheck(inpcount, inp);
	mlx = mlx_init();
	loadmap(&map, fd, mlx);
	mlx_loop(mlx);



	return (1);

}