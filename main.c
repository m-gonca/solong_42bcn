/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:53:51 by mogonzal          #+#    #+#             */
/*   Updated: 2022/09/20 16:13:32 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main (int argc, char **argv)
{
	t_game	game;
	
	game.moves = 0;
	ft_checker(argc, argv);
	printf("Everything is ok");
	return(0);
}