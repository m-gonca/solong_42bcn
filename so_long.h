/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:09:47 by mogonzal          #+#    #+#             */
/*   Updated: 2022/09/30 17:05:23 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include "libft/libft.h"
#include "mlx/mlx.h"

# define BUFFER_SIZE 1
# define SIZE 32

typedef struct s_game
{
	int				moves;
	char			**map_array;
	char			*map_line;
	int				fd;
	int				height;
	int				width;
	int				collect;
	int				player_x;
	int				player_y;
}					t_game;

typedef struct s_path
{
	char			**map_visited;
	int				collect;
}					t_path;

int 	ft_checker (int argc, char **argv, t_game *game);
int		ft_parameter_checker (int argc, char **argv, t_game *game);
int 	ft_array (t_game *game);
int 	ft_map_checker (t_game *game);

int 	ft_check_rectangular(t_game *game);
int		ft_check_borders(t_game *game);
int		ft_check_player(t_game *game);
int		ft_check_exit(t_game *game);
int		ft_check_collectibles(t_game *game);

void	ft_check_path(t_path *path);
int		ft_check_wall(char c);
int		ft_check_fill(char c);
int 	ft_find_in_array(char **map_array, char obj);

int 	ft_check_right(t_path *path);
int 	ft_check_left(t_path *path);
int 	ft_check_up(t_path  *path);
int 	ft_check_down(t_path  *path);

#endif
