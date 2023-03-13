/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prova_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:45:48 by aconta            #+#    #+#             */
/*   Updated: 2023/02/27 10:38:36 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>

int ft_close(void)
{
	exit(0);
	return (0);
}

int ft_keys(int key_code)
{
	printf("%d\n", key_code);
	return (0);
}

int main(void) 
{
	void *mlx;
	void *win;
	void *image;
	int	width;
	int	height;

	mlx = mlx_init();
	image = mlx_xpm_file_to_image(mlx, "water-melon.xpm", &width, &height);
	win = mlx_new_window(mlx, width, height, "Prova");
	mlx_put_image_to_window(mlx, win, image, 0, 0);
	mlx_hook(win, 17, 0, ft_close, (void*)0);
	mlx_hook(win, 2, 1L<<0, ft_keys, (void*)0);
	mlx_loop(mlx);
}
