/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:05:52 by mogonzal          #+#    #+#             */
/*   Updated: 2022/09/29 20:06:22 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_path(char **map_array, int y, int x, int collect)
{
	static int	temp_y = y;
	static int	temp_x = x;
	
	//checking right position
	if ((map_array[y][x + 1] != map_array[temp_y][temp_x]) && (map_array[y][x + 1] == 'C' || map_array[y][x + 1] == '0' ))
	{	
		temp_x = x;
		x++;
		if (map_array[y][x] == 'C')
			collect--;
		ft_check_path(map_array, y, x, collect);
	}
	else if((map_array[y][x - 1] != map_array[temp_y][temp_x]) && (map_array[y][x - 1] == 'C' || map_array[y][x - 1] == '0' ))
	{	
		temp_x = x;
		x--;
		if (map_array[y][x] == 'C')
			collect--;
		ft_check_path(map_array, y, x, collect);
	}
	else if ((map_array[y + 1][x] != map_array[temp_y][temp_x]) && (map_array[y + 1][x] == 'C' || map_array[y + 1][x] == '0'))		
	{	
		temp_y = y;
		y++;
		if (map_array[y][x] == 'C')
			collect--;
		ft_check_path(map_array, y, x, collect);
	}
	else if ((map_array[y - 1][x] != map_array[temp_y][temp_x]) && (map_array[y - 1][x] == 'C' || map_array[y - 1][x] == '0'))		
	{	
		temp_y = y;
		y--;
		if (map_array[y][x] == 'C')
			collect--;
		ft_check_path(map_array, y, x, collect);
	}
	else if (map_array[y][x + 1] == 'E' || map_array[y][x - 1] == 'E' || map_array[y + 1][x] == 'E' || map_array[y - 1][x] == 'E')
	{
		if(collect == 0)
		{
			ft_putstr_fd("Possible path found", 1);
			return(0);
		}
	}
}

int	ft_check_wall(char c)
{
	if (c != '1')
	{
		ft_putstr_fd("Map walls failed", 1);
		exit(1);
	}
	return (0);
}


int	ft_check_fill(char c)
{
	if (c != '0' && c != 'C' && c != 'E' && c != 'P' && c != '1')
	{
		ft_putstr_fd("Map has a wrong filling", 1);
		exit(1);
	}
	return (0);
}

int ft_find_in_array(char **map_array, char obj)
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

