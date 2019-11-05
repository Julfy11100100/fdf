/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:35:37 by mmark             #+#    #+#             */
/*   Updated: 2019/10/23 18:06:40 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

static int		zoom_func(t_fdf *fdf, int key)
{
	int		zoom;

	zoom = fdf->move->zoom;
	if (key == 69 && zoom <= 1000)
		fdf->move->zoom = zoom + 1;
	else if (key == 78 && zoom > 1)
		fdf->move->zoom = zoom - 1;
	redraw_line(fdf);
	return (0);
}

static int		x_func(t_fdf *fdf, int key)
{
	int			x;
	int			y;

	x = fdf->move->x;
	y = fdf->move->y;
	if (key == 2)
		fdf->move->x = x + 20;
	else
		fdf->move->x = x - 20;
	redraw_line(fdf);
	return (0);
}

static int		y_func(t_fdf *fdf, int key)
{
	int			x;
	int			y;

	x = fdf->move->x;
	y = fdf->move->y;
	if (key == 1)
		fdf->move->y = y + 20;
	else
		fdf->move->y = y - 20;
	redraw_line(fdf);
	return (0);
}

static int		z_func(t_fdf *fdf, int key)
{
	int			z;

	z = fdf->move->z;
	if (key == 67 && z < 25)
		fdf->move->z *= 1.04;
	else
		fdf->move->z *= 0.96;
	redraw_line(fdf);
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
		exit(0);
	else
		key_press_01(key, fdf);
	return (0);
}
