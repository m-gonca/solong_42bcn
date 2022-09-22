/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:37:58 by mogonzal          #+#    #+#             */
/*   Updated: 2022/09/22 18:47:46 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_check_rectangular(t_game game)
{
	int	y;

	y = 0;
	game.x = ft_strlen(game.map_array[y]);
	
	while (game.map_array[y])
	{
		if (ft_strlen(game.map_array[y]) != game.x)
		{
			ft_putstr_fd("Map is not a square or a rectangle", 1);
			exit(1);
		}
		y++;
	}
	return (0);
}

int	ft_check_borders(t_game game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	//run the array of strings
	while (game.map_array[y])
	{
		//running each string
		while (game.map_array[y][x])
		{
			//checking first and last string having only 1s
			if (y == 0 || y == ft_arraylen(game.map_array) - 1)
				ft_check_wall(game.map_array[y][x]);
			//checking first and last chars of the intermediate strings having only 1s
			else if (x == 0 || x == ft_strlen(game.map_array[y]) - 1)
				ft_check_wall(game.map_array[y][x]);
			//check that the filling are made of 0 P C or E
			else if (x != 0 || x != ft_strlen(game.map_array[y]) - 1)
				ft_check_fill(game.map_array[y][x]);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	ft_check_player(t_game game)
{
	int p;
	
	p = ft_find_in_array(game.map_array, 'P');
	if (p != 1)
	{
		ft_putstr_fd("Map has a wrong num of Players", 1);
		exit(1);
	}
	return (0);
}

int	ft_check_exit(t_game game)
{
	int e;
	
	e = ft_find_in_array(game.map_array, 'E');
	if (e != 1)
	{
		ft_putstr_fd("Map has a wrong num of Exits", 1);
		exit(1);
	}
	return (0);
}

int	ft_check_collectibles(t_game game)
{
	game.collect = ft_find_in_array(game.map_array, 'C');

	if (game.collect == 0)
	{
		ft_putstr_fd("Map doesn't have enough collectibles ", 1);
		exit(1);
	}
	return (0);
}