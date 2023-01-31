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
		
		path.map_visited = path.map_visited[game->height][game->width];
		path.collect = game->collect;
		
		ft_memcpy(path->map_visited, game->map_array, sizeof(char)*game->height*game->width);

		//testear esto

		// path.player_y--;
		// printf("%d" ,path.player_y);
		// printf("%d" ,game.player_y);

		if(ft_check_path(game->map_array, &path, game->player_y, game->player_x) == 1)
		{
			ft_putstr_fd("No Possible path found", 1);
			exit(1);
		}
		else return(0);
		
	}


int	ft_check_path(char **map, t_path path, int i, int j)
{
	printf("\n\nhe entrado en CHECK PATH\n");
	char **visited = path->map_visited;
	bool exit_found = false;

	if(map[i][j] != 1 && visited[i][j] != 1){
		visited[i][j] = 1;
		if(map[i][j] == 'C') path->collect--;
		if(map[i][j] == 'E') exit_false = true;
		if(exit_found == true && path->collect == 0){
			ft_putstr_fd("Possible path found", 1);
			return (0);
		}
		//go up
		int up = ft_check_path(map, visited, i - 1, j);
		if(up == 0) return (0);

		//go right
		int right = ft_check_path(map, visited, i, j + 1);
		if(right == 0) return (0);

		//go down
		int down = ft_check_path(map, visited, i + 1, j);
		if(down == 0) return (0);

		//go left
		int left = ft_check_path(map, visited, i, j - 1);
		if(left == 0) return (0);	
	}
	return 1;
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
