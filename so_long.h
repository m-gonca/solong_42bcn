/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:09:47 by mogonzal          #+#    #+#             */
/*   Updated: 2022/09/22 18:06:04 by mogonzal         ###   ########.fr       */
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
#include "getnextline/get_next_line.h"

# define BUFFER_SIZE 1
# define SIZE 32

typedef struct s_game
{
	int				moves;
	char			**map_array;
	int				fd;
	int				y;
	int				x;
	int				collect;
}					t_game;

int ft_checker (int argc, char **argv, t_game game);
int	ft_parameter_checker (int argc, char **argv, t_game game);
int ft_array (t_game game);
int ft_map_checker (t_game game);

int ft_check_rectangular(t_game game);
int	ft_check_borders(t_game game);
int	ft_check_player(t_game game);
int	ft_check_exit(t_game game);
int	ft_check_collectibles(t_game game);

// int	ft_check_path(char **map_array);
int	ft_check_wall(int num);
int	ft_check_fill(int num);
int ft_find_in_array(char **map_array, int obj);



