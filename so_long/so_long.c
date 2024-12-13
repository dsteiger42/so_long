#include "so_long.h"

static int	argv_checker(char *argv)
{
	if (!argv)
		return (0);
	check_errors(argv);
    check_map_name(argv);
	return (0);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
//      check_errors(argv);
//      check_map_name(argv);
    }
    else
    {
        ft_printf("Wrong number of arguments!");
        return (0);
    }

}
