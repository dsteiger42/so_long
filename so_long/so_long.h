#ifndef SO_LONG_H
#define SO_LONG_H

# define WALLS '1'
# define FLO0R '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define START_POS 'P'

# define W 13
# define A 0
# define S 1
# define D 2

# define UARROW 126
# define LARROW 123
# define DARROW 125
# define RARROW 124

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "so_long.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
    char **map;
    int fd;
    int height;
    int width;
    int player_count;
    int collectibles_count;
    int exit_count;
    

}   t_map;

#endif