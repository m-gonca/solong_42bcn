/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:24:42 by mogonzal          #+#    #+#             */
/*   Updated: 2023/01/31 18:24:42 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void mlx_new_window(t_mlx *mlx)
// {
// 	mlx->mlx = mlx_init();
// 	mlx->win = mlx_new_window(mlx->mlx, 1920, 1080, "so_long");
// 	mlx->img = mlx_new_image(mlx->mlx, 1920, 1080);
// 	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
// }

#include "/so_long.h"

void ft_mlx_window(t_mlx *mlx, t_game *game)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx, 640, 360, "Testeandito las ventanitas del dichoso jueguito");
	mlx_loop(mlx);

}
