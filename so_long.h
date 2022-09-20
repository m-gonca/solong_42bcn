/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:09:47 by mogonzal          #+#    #+#             */
/*   Updated: 2022/09/20 13:29:53 by mogonzal         ###   ########.fr       */
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
	void			*content;
	struct s_list	*next;
}					t_game;