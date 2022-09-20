/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:13:40 by mogonzal          #+#    #+#             */
/*   Updated: 2022/09/20 13:41:31 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// 1-check parameters are correct:
//		-2 parameters
//		-2nd parameter is a .ber file
// 2-check map is valid:
// 		-check the map is sorrounded by walls
// 		-check the map has one exit
// 		-check the map only has one player/entrance
// 		-check map has minimum 1 collectible
// 3-check map has a valid path to exit:
// 		-no idea wtf to do with this btm

int ft_parameter_checker (int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Add one map as parameter", 1);
		return (0);
	}
	if (ft_strncmp(argv[1], ".ber", 4) != 0)
	{
		ft_putstr_fd("Map must be a .ber file", 1);
		return (0);
	}	

	
}


int ft_checker (int argv, char **argc)
{
	ft_parameter_checker(argv, argc);

	
	return (0);
}