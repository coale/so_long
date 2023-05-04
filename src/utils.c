/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:10:10 by aconta            #+#    #+#             */
/*   Updated: 2023/04/26 12:18:26 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_char(char **map, char c)
{
	int	counter;
	int	i;
	int	j;

	counter = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

int	foreign_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' || map[i][j] != '0' || map[i][j] != 'E' \
			|| map[i][j] != 'P' || map[i][j] != 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_matrix_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
