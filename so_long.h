/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:09:47 by mogonzal          #+#    #+#             */
/*   Updated: 2022/09/29 17:50:24 by mogonzal         ###   ########.fr       */
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

int ft_checker (int argc, char **argv, t_game *game);
int	ft_parameter_checker (int argc, char **argv, t_game *game);
int ft_array (t_game *game);
int ft_map_checker (t_game *game);

int ft_check_rectangular(t_game *game);
int	ft_check_borders(t_game *game);
int	ft_check_player(t_game *game);
int	ft_check_exit(t_game *game);
int	ft_check_collectibles(t_game *game);

int	ft_check_path(char **map_array, int y, int x, int collect);
int	ft_check_wall(char c);
int	ft_check_fill(char c);
int ft_find_in_array(char **map_array, char obj);


#endif
