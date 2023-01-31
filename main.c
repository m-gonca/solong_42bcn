/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:53:51 by mogonzal          #+#    #+#             */
/*   Updated: 2022/09/27 15:05:06 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (int argc, char **argv)
{
	t_game	game;
	t_mlx	mlx;
	
	game.moves = 0;

	//Check if the map is valid
	if(ft_checker(argc, argv, &game) == 0) printf("Everything is ok");
	
	//Open a window with the map, in which every number is a sprite
	ft_mlx_window(&mlx, &game);



	return(0);
}