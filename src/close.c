/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:02:49 by aconta            #+#    #+#             */
/*   Updated: 2023/04/05 11:05:17 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_game *game)
{
	ft_free_map(game->map);
	mlx_destroy_image(game->mlx, game->pers.image);
	mlx_destroy_image(game->mlx, game->floor.image);
	mlx_destroy_image(game->mlx, game->wall.image);
	mlx_destroy_image(game->mlx, game->exit.image);
	mlx_destroy_image(game->mlx, game->coll.image);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}
