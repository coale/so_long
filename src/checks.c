/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:04:39 by aconta            #+#    #+#             */
/*   Updated: 2023/04/26 12:15:10 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *path)
{
	char	*ext;

	ext = ft_strchr(path, '.');
	if (ext != NULL )
	{
		if (ft_strncmp(ext, ".ber", 5) == 0)
			return (0);
	}
	return (1);
}

int	ft_check_rectangular(char **map)
{
	int		i;
	size_t	size;

	i = 1;
	size = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != size)
			return (1);
		i++;
	}
	return (0);
}

int	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(map[0]) - 1;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][j] != '1')
			return (1);
		i++;
	}
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	all_the_checks(char *path)
{
	char	**map;

	if (check_ber(path) == 0)
	{
		map = read_map(path);
		if (map == NULL)
			return (1);
		if (ft_check_rectangular(map) || check_walls(map)
			|| count_char(map, 'P') != 1 || count_char(map, 'E') != 1
			|| count_char(map, 'C') < 1 || ft_path_check(map)
			|| foreign_char(map) != 1)
		{
			ft_free_map(map);
			return (1);
		}
		ft_free_map(map);
	}
	else
		return (1);
	return (0);
}
