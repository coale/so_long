/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:10:13 by aconta            #+#    #+#             */
/*   Updated: 2023/04/05 09:56:10 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

t_point	pos_char(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return ((t_point){j, i});
			j++;
		}
		i++;
	}
	return ((t_point){-1, -1});
}

void	flood_fill(char **map, int max_x, int max_y, t_point pos_p)
{
	if (pos_p.x < 0 || pos_p.y < 0 || pos_p.x >= max_x \
		|| pos_p.y >= max_y || map[pos_p.y][pos_p.x] == '1')
		return ;
	if (map[pos_p.y][pos_p.x] == 'E')
	{
		map[pos_p.y][pos_p.x] = '1';
		return ;
	}
	map[pos_p.y][pos_p.x] = '1';
	flood_fill(map, max_x, max_y, (t_point){pos_p.x + 1, pos_p.y});
	flood_fill(map, max_x, max_y, (t_point){pos_p.x - 1, pos_p.y});
	flood_fill(map, max_x, max_y, (t_point){pos_p.x, pos_p.y + 1});
	flood_fill(map, max_x, max_y, (t_point){pos_p.x, pos_p.y - 1});
}

int	ft_path_check(char **map)
{
	int	i;
	int	j;

	flood_fill(map, ft_strlen(map[0]), ft_matrix_height(map), \
					pos_char(map, 'P'));
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
