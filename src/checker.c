/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:13:40 by mogonzal          #+#    #+#             */
/*   Updated: 2022/09/20 16:38:47 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// 1-check parameters are correct:
//		-2 parameters
//		-2nd parameter is a .ber file
//		-check it can be opened and a that the fd is saved
// 2-check map is valid:
// 		-check the map is sorrounded by walls
// 		-check the map has one exit
// 		-check the map only has one player/entrance
// 		-check map has minimum 1 collectible
// 3-check map has a valid path to exit:
// 		-no idea wtf to do with this btm

int	ft_parameter_checker (int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_putstr_fd("Add one map as parameter", 1);
		exit(1);
	}
	if (ft_strncmp(&file_name[ft_strlen(argv[1]) - 4], ".ber") != 0)
	{
		ft_putstr_fd("Map must be a .ber file", 1);
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Map can't be opened", 1);
		exit(1);
	}
	return (fd);	
}

int ft_components_checker (char *map, int fd)
{
	int	i;
	char *line;
	char **map_array;
	
	i = 0;
	//chequear el error del getnextline
	while (get_next_line(fd, &line) > 0)
	{
		map_array[i] = line;
		i++;
	}
	ft_check_borders(map_array);
	ft_check_player(map_array);
	ft_check_exit(map_array);
	ft_check_collectibles(map_array);
	
	return (map_array);
}

int	ft_path_checker (char **map_array)
{
	//no idea wtf to do with this btm
}


int ft_checker (int argc, char **argv)
{
	int fd;
	char **map_array;
	
	fd = ft_parameter_checker(argv, argc);
	map_array = ft_components_checker(argv[1], fd);
	ft_path_checker(map_array);
	
	return (map_array);
}