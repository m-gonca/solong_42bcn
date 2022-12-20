/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:05:52 by mogonzal          #+#    #+#             */
/*   Updated: 2022/12/20 20:30:25 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


	int ft_copy_map(t_game game)
	{
		t_path path;
		
		path.map_array = path.map_array[game->height][game->width];
		path.player_y = game->player_y;
		path.player_x = game->player_x;
		path.collect = game->collect;
		
		ft_memcpy(path->map_array, game->map_array, sizeof(char)*5*5);




		
	}

/*int ft_check_right(t_path *path)
{
	char 	**map;
	int		x;
	int		y;
	
	map = path->map_array;
	x = path->player_x;
	y = path->player_y;

	printf("\n\nhe entrado en posicion DERECHA\n");
	printf("y = %d\n", path->player_y);
	printf("x = %d\n", path->player_x);
	sleep(2);
	
	if(map[y][x + 1] == 'E' && path->collect == 0)
	{
		ft_putstr_fd("Possible path found", 1);
		exit(1);
	}
	else if ((x + 1 != path->temp_x) && (map[y][x + 1] == 'C'||\
	map[y][x + 1] == '0' || map[y][x + 1] == 'P' || map[y][x + 1] == 'E'))
	{	
		path->player_x++;
		x++;
		if (map[y][x] == 'C')
			path->collect--;
		printf("el player ahora esta en x = %d\n", path->player_x);
		printf("la x de esta funcion es x = %d\n", x);
		printf("el collect es = %d\n", path->collect);
		ft_check_path(path);
	}
	path->temp_x = x - 1;
	// else 
	// 	ft_check_left(path);
	return(0);
}

int ft_check_left(t_path *path)
{
	char 	**map;
	int		x;
	int		y;

	map = path->map_array;
	x = path->player_x;
	y = path->player_y;
	printf("\n\nhe entrado en posicion IZQUIERDA\n");
	printf("y = %d\n", path->player_y);
	printf("x = %d\n", path->player_x);
	sleep(2);
	
	if(map[y][x - 1] == 'E' && path->collect == 0)
	{
		ft_putstr_fd("Possible path found", 1);
		return(1);
	}
	else if((x - 1 != path->temp_x) && (map[y][x - 1] == 'C' || map[y][x - 1] == '0'\
	 || map[y][x - 1] == 'P' || map[y][x - 1] == 'E'))
	{	
		path->player_x--;
		x--;
		if (map[y][x] == 'C')
			path->collect--;
		printf("el player ahora esta en x = %d\n", path->player_x);
		printf("la x de esta funcion es x = %d\n", x);
		printf("el collect es = %d\n", path->collect);
		ft_check_path(path);
	}
	// else 
	// 	ft_check_up(path);
	return(0);
}

int ft_check_up(t_path  *path)
{
	char 	**map;
	int		x;
	int		y;

	map = path->map_array;
	x = path->player_x;
	y = path->player_y;
	if(map[y + 1][x] == 'E' && path->collect == 0)
	{
		ft_putstr_fd("Possible path found", 1);
		return(1);
	}
	else if ((y + 1 != path->temp_y ) && (map[y + 1][x] == 'C' \
	|| map[y + 1][x] == '0' || map[y + 1][x] == 'P' || map[y + 1][x] == 'E'))		
	{	
		printf("\n\nhe entrado en posicion SUPERIOR\n");
		path->player_y++;
		y++;
		if (map[y][x] == 'C')
			path->collect--;

		ft_check_path(path);
	}
	// else 
	// 	ft_check_down(path);
	return(0);
}

int ft_check_down(t_path  *path)
{
	char 	**map;
	int		x;
	int		y;

	map = path->map_array;
	x = path->player_x;
	y = path->player_y;
	if(map[y - 1][x] == 'E' && path->collect == 0)
	{
		ft_putstr_fd("Possible path found", 1);
		return(1);
	}
	else if ((y - 1 != path->temp_y) && (map[y - 1][x] == 'C' \
	|| map[y - 1][x] == '0' || map[y - 1][x] == 'P' || map[y - 1][x] == 'E'))		
	{	
		printf("\n\nhe entrado en posicion INFERIOR\n\n");
		path->player_y--;
		y--;
		if (map[y][x] == 'C')
			path->collect--;
		ft_check_path(path);
	}
	// else
		
	return(0);
}

void	ft_check_path(t_path *path)
{
	printf("\n\nhe entrado en CHECK PATH\n");
	printf("y = %d\n", path->player_y);
	printf("x = %d\n", path->player_x);
	path->temp_y = path->player_y;
	path->temp_x = path->player_x;
	printf("initial temp y = %d\n", path->temp_y);
	printf("initial temp x = %d\n", path->temp_x);
	if(ft_check_right(path) == 1)
		return;
	printf("estoy pasando de right a left\n");
	if(ft_check_left(path) == 1)
		return;
	if(ft_check_up(path) == 1)
		return;
	if(ft_check_down(path) == 1)
		return;

	printf("ending temp y = %d\n", path->temp_y);
	printf("ending temp x = %d\n", path->temp_x);
	printf("no he visto ningun valor posibe\n");
}*/








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
