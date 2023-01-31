/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:13:40 by mogonzal          #+#    #+#             */
/*   Updated: 2022/12/20 20:16:25 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/so_long.h"

// 1-check parameters are correct:
//		-2 parameters
//		-2nd parameter is a .ber file
//		-check it can be opened and a that the fd is saved
// 2-check map is valid:
// 		-check the map is sorrounded by walls
// 		-check the map has one exit
// 		-check the map only has one player/entrance
// 		-check map has minimum 1 collectible
// 3-check map has a valid path to exit:
// 		-go through the array starting from the P 

int	ft_parameter_checker (int argc, char **argv, t_game *game)
{
	char	*str;
	//---chequear para bajar la linea 31 despues de comprobar que hay dos parametros y no aqui arriba
	str = argv[1];
	if (argc != 2)
	{
		ft_putstr_fd("Add one map as parameter", 1);
		exit(1);
	}
	if (ft_strncmp(&str[ft_strlen(str) - 4], ".ber", 4) != 0)
	{
		ft_putstr_fd("Map must be a .ber file", 1);
		exit(1);
	}
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
	{
		ft_putstr_fd("Map can't be opened", 1);
		exit(1);
	}
	return (0);	
}

int ft_array (t_game *game)
{
	char *line;
	
	game->height = 0;
	game->map_line = "";
	line = "";
	while (line)
	{
		line = get_next_line(game->fd);
		//printf("%s", line);
		if (!line)
			break;
		if(*line == '\n')
		{			
			ft_putstr_fd("Empty line in map", 1);
			exit(1);
		}
		else if(game->height == 0)
			game->width = ft_strlen(line) - 1;
		game->map_line = ft_strjoin(game->map_line, line);
		game->height++;
		free(line);
	}
	game->map_array = ft_split(game->map_line, '\n');
	close(game->fd);
	return (0);
}

int ft_map_checker (t_game *game)
{
	ft_check_rectangular(game);
	ft_check_borders(game);
	ft_check_player(game);
	ft_check_exit(game);
	ft_check_collectibles(game);
	ft_check_path(game);
	printf("saliendo en map checker\n");
	//printf(" \n\n\n ESTO ES UNA PRUEBA PARA SABER SI SE MODIFICA ALGUN DATO DE LA ESTRUCTURA GAME %d\n\n\n", game->collect);

	return (0);
}

int ft_checker (int argc, char **argv, t_game *game)
{	
	//printf("entrando en checker\n");
	ft_parameter_checker(argc, argv, game);
	ft_array(game);
	ft_map_checker(game);
	
	return (0);
}