#include "so_long.h"

void	free_arr(char **arr, int height)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (i < height && arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	free_temp_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}


char	**copy_map(char **map, int height)
{
	char		**temp;
	int			i;

	if (!map || height <= 0)
		return (NULL);
	temp = (char **)malloc(sizeof(char *) * (height + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < height)
	{
		temp[i] = strdup(map[i]);
		if (!temp[i])
		{
			free_arr(temp, i);
			return (NULL);
		}
		i++;
	}
	temp[i] = NULL;
	return (temp);
}

int	flood_fill_map(char **map, int y, int x, t_vars *vars)
{
	if (!map || x < 1 || y < 1 || !vars)
		return (-1);
	if (map[y][x] == WALLS || map[y][x] == '2')
		return (1);
	if (map[y][x] == COLLECTIBLE)
		vars->collectible_count--;
	if (map[y][x] == EXIT)
	{
		vars->exit_count = 1;
		return (1);
	}
	map[y][x] = '2';
	flood_fill_map(map, y - 1, x, vars);
	flood_fill_map(map, y + 1, x, vars);
	flood_fill_map(map, y, x + 1, vars);
	flood_fill_map(map, y, x - 1, vars);
	return (1);
}

int	check_flood_fill(char **map, t_vars *vars)
{
	if (!map || !vars || vars->collectible_count != 0 || vars->exit_count != 1)
	{
		printf("ERROR: Path is blocked. Collectibles or exit are unreachable.\n");
		free_temp_map(map);
		return (-1);
	}
	free_temp_map(map); 
	return (1);
}


int	check_valid_path(t_vars *vars)
{
	char	**temp;

	if (!vars || !vars->map)
		return (-1);
	temp = copy_map(vars->map, vars->height);
	if (!temp)
		return (-1);
    vars->collectible_count = vars->temp_coll;
	if (flood_fill_map(temp, vars->player_y, vars->player_x, vars) != 1)
	{
		free_temp_map(temp);
		exit_game(vars);
	}
	if (check_flood_fill(temp, vars) != 1)
	{
		free_temp_map(temp);
		exit_game(vars);
	}
	return (1);
}
