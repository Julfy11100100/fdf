/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmark <mmark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:35:37 by mmark             #+#    #+#             */
/*   Updated: 2019/08/14 20:46:31 by mmark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

static int		zoom_func(t_fdf *fdf, int key)
{
	t_line	*line;
	int		zoom;

	zoom = fdf->move->zoom;
	line = line_new();
	if (key == 69)
	{
		if (zoom <= 1000)
			fdf->move->zoom = zoom + 1;
	}
	else
	{
		if (zoom > 1)
			fdf->move->zoom = zoom - 1;
	}
	ft_memset(fdf->img.data, 0x000000, fdf->max);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	print(fdf, line);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.img_ptr, 0, 0);
	fdf_message(fdf);
	del_line(&line);
	return (0);
}

static int		x_func(t_fdf *fdf, int key)
{
	t_line		*line;
	int			x;
	int			y;

	line = line_new();
	x = fdf->move->x;
	y = fdf->move->y;
	if (key == 2)
	{
		fdf->move->x = x + 10;
		fdf->move->y = y - 10;
	}
	else
	{
		fdf->move->x = x - 10;
		fdf->move->y = y + 10;
	}
	ft_memset(fdf->img.data, 0x000000, fdf->max);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	print(fdf, line);
	mlx_put_image_to_window(fdf->mlx_ptr,
		fdf->win_ptr, fdf->img.img_ptr, 0, 0);
	fdf_message(fdf);
	del_line(&line);
	return (0);
}

static int		y_func(t_fdf *fdf, int key)
{
	t_line		*line;
	int			x;
	int			y;

	line = line_new();
	x = fdf->move->x;
	y = fdf->move->y;
	if (key == 1)
	{
		fdf->move->y = y + 10;
		fdf->move->x = x + 10;
	}
	else
	{
		fdf->move->y = y - 10;
		fdf->move->x = x - 10;
	}
	ft_memset(fdf->img.data, 0x000000, fdf->max);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	print(fdf, line);
	mlx_put_image_to_window(fdf->mlx_ptr,
		fdf->win_ptr, fdf->img.img_ptr, 0, 0);
	fdf_message(fdf);
	del_line(&line);
	return (0);
}

static int		z_func(t_fdf *fdf, int key)
{
	t_line		*line;
	int			z;

	line = line_new();
	z = fdf->move->z;
	if (key == 67)
	{
		fdf->move->z = z + 1;
	}
	else
	{
		fdf->move->z = z - 1;
	}
	ft_memset(fdf->img.data, 0x000000, fdf->max);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	print(fdf, line);
	mlx_put_image_to_window(fdf->mlx_ptr,
		fdf->win_ptr, fdf->img.img_ptr, 0, 0);
	fdf_message(fdf);
	del_line(&line);
	return (0);
}

int				key_press(int key, t_fdf *fdf)
{
	if (key == 69 || key == 78)
		zoom_func(fdf, key);
	if (key == 0 || key == 2)
		x_func(fdf, key);
	if (key == 13 || key == 1)
		y_func(fdf, key);
	if (key == 75 || key == 67)
		z_func(fdf, key);
	if (key == 53)
	{
		exit(0);
	}
	return (0);
}
