#include "so_long.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_printf("Wrong number of arguments!");
        return (0);
    }
    else
    {
        check_errors(argv);
        check_map_name(argv);
    }

}