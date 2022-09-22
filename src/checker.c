/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:13:40 by mogonzal          #+#    #+#             */
/*   Updated: 2022/09/22 18:06:07 by mogonzal         ###   ########.fr       */
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

int	ft_parameter_checker (int argc, char **argv, t_game game)
{
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
	game.fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Map can't be opened", 1);
		exit(1);
	}
	return (0);	
}

int ft_array (t_game game)
{
	int	y;
	
	y = 0;
	//chequear el error del getnextline
	while (get_next_line(game.fd) > 0)
	{
		game.map_array[y] = get_next_line(game.fd);
		y++;
	}
	close(game.fd);
	game.y = y;
	return (0);
}

int ft_map_checker (t_game game)
{
	ft_check_rectangular(game);
	ft_check_borders(game);
	ft_check_player(game);
	ft_check_exit(game);
	ft_check_collectibles(game);
	// ft_check_path(game);
	
	return (0);
}

int ft_checker (int argc, char **argv, t_game game)
{	
	ft_parameter_checker(argv, argc, game);
	ft_array(game);
	ft_map_checker(game);
	
	return (0);
}