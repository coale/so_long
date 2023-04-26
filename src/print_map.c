/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 09:44:21 by aconta            #+#    #+#             */
/*   Updated: 2023/04/05 14:31:24 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assign_image(t_game *game)
{
	game->pers.image = mlx_xpm_file_to_image(game->mlx, \
		"textures/pers.xpm", &game->pers.size.x, &game->pers.size.y);
	game->floor.image = mlx_xpm_file_to_image(game->mlx, \
		"textures/floor.xpm", &game->floor.size.x, &game->floor.size.y);
	game->wall.image = mlx_xpm_file_to_image(game->mlx, \
		"textures/wall.xpm", &game->wall.size.x, &game->wall.size.y);
	game->exit.image = mlx_xpm_file_to_image(game->mlx, \
		"textures/exit.xpm", &game->exit.size.x, &game->exit.size.y);
	game->coll.image = mlx_xpm_file_to_image(game->mlx, \
		"textures/coll.xpm", &game->coll.size.x, &game->coll.size.y);
}

void	put_image(t_game *game, int i, int j, void *image)
{
	int	x;
	int	y;

	x = game->wall.size.x;
	y = game->wall.size.y;
	mlx_put_image_to_window(game->mlx, game->window, image, j * x, i * y);
}

void	print_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '1')
				put_image(game, i, j, game->wall.image);
			else if (game->map[i][j] == '0')
				put_image(game, i, j, game->floor.image);
			else if (game->map[i][j] == 'P')
				put_image(game, i, j, game->pers.image);
			else if (game->map[i][j] == 'E')
				put_image(game, i, j, game->exit.image);
			else if (game->map[i][j] == 'C')
				put_image(game, i, j, game->coll.image);
		}
	}
}

void	check_and_update(t_game *game, t_point to_check)
{
	static int	count;

	if (game->map[to_check.y][to_check.x] == '1' \
					|| (game->map[to_check.y][to_check.x] == 'E' \
							&& game->coll_count > 0))
		return ;
	else if (game->map[to_check.y][to_check.x] == 'E' && game->coll_count == 0)
	{
		ft_printf("\nYou win!\n");
		ft_close(game);
	}
	else if (game->map[to_check.y][to_check.x] == 'C')
	{
		game->coll_count--;
		game->map[to_check.y][to_check.x] = '0';
	}
	count++;
	mlx_put_image_to_window(game->mlx, game->window, game->floor.image, \
		game->pers_pos.x * game->floor.size.x, \
			game->pers_pos.y * game->floor.size.y);
	game->pers_pos = to_check;
	mlx_put_image_to_window(game->mlx, game->window, game->pers.image, \
		game->pers_pos.x * game->pers.size.x, \
			game->pers_pos.y * game->pers.size.y);
	ft_printf("\rYOUR MOVES: %d", count);
}

int	ft_keys(int key_code, t_game *game)
{
	if (key_code == ESC)
		ft_close(game);
	else if (key_code == UP || key_code == 'w')
		check_and_update(game, (t_point){game->pers_pos.x, \
						game->pers_pos.y - 1});
	else if (key_code == DOWN || key_code == 's')
		check_and_update(game, (t_point){game->pers_pos.x, \
						game->pers_pos.y + 1});
	else if (key_code == RIGHT || key_code == 'd')
		check_and_update(game, (t_point){game->pers_pos.x + 1, \
						game->pers_pos.y});
	else if (key_code == LEFT || key_code == 'a')
		check_and_update(game, (t_point){game->pers_pos.x - 1, \
						game->pers_pos.y});
	return (0);
}
