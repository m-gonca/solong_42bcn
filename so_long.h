/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:09:47 by mogonzal          #+#    #+#             */
/*   Updated: 2022/09/20 16:13:37 by mogonzal         ###   ########.fr       */
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
	char			**map_array;
	int				moves;
}					t_game;

int ft_checker (int argc, char **argv)
int	ft_parameter_checker (int argc, char **argv);
int ft_components_checker (char *map, int fd);
int	ft_path_checker (char *map);
int	ft_check_borders(map_array);
int	ft_check_player(map_array);
int	ft_check_exit(map_array);
int	ft_check_collectibles(map_array);


