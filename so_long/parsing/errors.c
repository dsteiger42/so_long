#include "so_long.h"

static int horizontal_walls(t_map *game)     
{
    int width;
    int j;

    // check if the game pointer and map pointer inside game struct are NULL
    if (!game || !game->map || game->width <= 0 || game->height <= 0)
        return (0);

    width = game->width;
    j = 0;
    while (j < width)
    {
        if (game->map[0][j] != '1' || game->map[game->height - 1][j] != '1')
            return (0);
        j++;
    }
    return (1);
}

static int vertical_walls(t_map *game)
{
    int i;
    int width;

    if (!game || !game->map || game->width <= 0 || game->height <= 0)
        return (0);

    i = 0;
    width = game->width;
    while (i < game->height)
    {
        if (game->map[i][0] != '1' || game->map[i][width - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

static void walls(t_map *game)
{
    int	verticalwalls;
	int	horizontalwalls;

    verticalwalls = vertical_walls(game);
	horizontalwalls = horizontal_walls(game);

    if (!(vertical_walls == 1) || !(horizontal_walls == 1))
    {
        ft_printf("\nThis map is missing the walls\n");
        return (0);
    }
    return (1);
}
void valid_characters(t_map *game, int height, int width)
{
    if (game->map[height][width] != '1' &&
            game->map[height][width] != '0' &&
            game->map[height][width] != 'P' &&
            game->map[height][width] != 'C' &&
            game->map[height][width] != 'E' &&
            game->map[height][width] != '\n')
        ft_printf("Error, invalid character");
    if (game->map[height][width] == 'P')
        game->player_count++;
    if (game->map[height][width] == 'C')
        game->collectibles_count++;
    if (game->map[height][width] == 'E')
        game->exit_count++;
    
    if (game->player_count != 1 && game->exit_count != 1 && game->collectibles_count < 1)
        ft_printf("Ups, issue with your player, exit or collectible!");
}

void check_errors(t_map *game)
{
    int height;
    int width;

    walls(game);
    height = 0;
    while (height < game->height)
    {
        int width = 0;
        while (width < game->width)
        {
            valid_characters(game, height, width);
            width++;
        }
        height++;
    }
}
