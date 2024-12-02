#include "so_long.h"

void check_map_name(char *map_name)
{
    t_map   file;
	int		len;

	if (!map_name)
		ft_printf("ERROR: Invalid pointer to file name\n");
	file.fd = open(map_name, O_RDONLY);
	if (file.fd < 0)
		ft_printf("ERROR: Error opening the file\n");
	len = ft_strlen(map_name);
	if (len < 4 || ft_strncmp(&map_name[len - 4], ".ber", 4) != 0) // If != 0, it means the strings are different.
		ft_printf("ERROR: Invalid map name, should end with .ber\n");
	else
		ft_putstr_fd("Check name passed\n", 1);
	close(file.fd);

}