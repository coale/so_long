/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:10:21 by aconta            #+#    #+#             */
/*   Updated: 2023/04/26 12:10:58 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>

# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
# define ESC 65307

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_image
{
	void	*image;
	t_point	size;
}	t_image;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_point	pers_pos;
	t_image	pers;
	t_image	floor;
	t_image	wall;
	t_image	exit;
	t_image	coll;
	int		coll_count;
	char	**map;
	t_point	map_size;
}	t_game;

char	**read_map(char *path);
void	print_map(t_game *game);
void	assign_image(t_game *game);
int		ft_close(t_game *game);
int		ft_keys(int key_code, t_game *game);
void	ft_free_map(char **map);
int		ft_matrix_height(char **map);
int		ft_path_check(char **map);
t_point	pos_char(char **map, char c);
int		count_char(char **map, char c);
int		all_the_checks(char *path);
int		check_ber(char *path);
int		foreign_char(char **map);

#endif
