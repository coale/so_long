/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:50:25 by aconta            #+#    #+#             */
/*   Updated: 2023/04/05 14:31:42 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*long_map(char *temp, char *long_line)
{
	char	*dest;

	dest = ft_strjoin(long_line, temp);
	free(temp);
	free(long_line);
	return (dest);
}

char	**read_map(char *path)
{
	char	**map;
	char	*temp;
	char	*long_line;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	long_line = malloc(1);
	long_line[0] = '\0';
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		long_line = long_map(temp, long_line);
	}
	map = ft_split(long_line, '\n');
	free(long_line);
	return (map);
}

void	ft_game(char *path)
{
	t_game	game;

	game.map = read_map(path);
	game.coll_count = count_char(game.map, 'C');
	game.pers_pos = pos_char(game.map, 'P');
	game.map_size = (t_point){ft_strlen(game.map[0]), \
		ft_matrix_height(game.map)};
	game.mlx = mlx_init();
	assign_image(&game);
	game.window = mlx_new_window(game.mlx, game.wall.size.x * game.map_size.x, \
		game.wall.size.y * game.map_size.y, "so_long");
	print_map(&game);
	mlx_hook(game.window, 2, (1L << 0), ft_keys, &game);
	mlx_hook(game.window, 17, 0, ft_close, &game);
	mlx_loop(game.mlx);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (all_the_checks(argv[1]) == 0)
		{
			ft_game(argv[1]);
		}
		else
			ft_printf("Error\n");
		if (check_ber(argv[1]) == 1)
			ft_printf("Invalid map extension, it should be a .ber file\n");
	}
	else
	{
		ft_printf("Error\nYou should select a map");
		return (1);
	}
}
