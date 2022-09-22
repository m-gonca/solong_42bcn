/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:05:52 by mogonzal          #+#    #+#             */
/*   Updated: 2022/09/22 18:51:15 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// int	ft_check_path(char **map_array)
// {
// 	//no idea wtf to do with this btm
// }

int	ft_check_wall(int num)
{
	if (num != '1')
	{
		ft_putstr_fd("Map walls failed", 1);
		exit(1);
	}
	return (0);
}


int	ft_check_fill(int num)
{
	if (num != 0 || num != 'C' || num != 'E' || num != 'P')
	{
		ft_putstr_fd("Map has a wrong filling", 1);
		exit(1);
	}
	return (0);
}

int ft_find_in_array(char **map_array, int obj)
{
	int	y;
	int	x;
	int	counter;

	y = 0;
	x = 0;
	counter = 0;
	while (map_array[y])
	{
		while (map_array[y][x])
		{
			if (map_array[y][x] == obj)
				counter++;
			x++;
		}
		x = 0;
		y++;
	}
	return (counter);
}

