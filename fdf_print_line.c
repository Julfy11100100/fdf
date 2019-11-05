/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 13:36:12 by mmark             #+#    #+#             */
/*   Updated: 2019/10/23 18:24:23 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

static int		kostyl(t_fdf *fdf, t_line *line, int i)
{
	if (i == 1)
		return ((fdf->max / 8) + line->y2 * IMG_W + line->x2 + IMG_W / 2 +
		fdf->move->x + fdf->move->y * IMG_W);
	else
		return ((fdf->max / 8) + line->c->y * IMG_W + line->c->x + IMG_W / 2 +
		fdf->move->x + fdf->move->y * IMG_W);
}

static int		kostyl_2(t_fdf *fdf, t_line *line, int i, int f)
{
	if (f == 1 && i > 0 && i < fdf->max &&
		(fdf->max / 8 + line->y2 + fdf->move->y) < IMG_H &&
		(line->x2 < IMG_W / 2 - fdf->move->x) &&
		(line->x2 > -IMG_W / 2 - fdf->move->x))
		return (1);
	if (f == 2 && i > 0 && i < fdf->max &&
		(line->c->y + fdf->move->y) < IMG_H &&
		(line->c->x < IMG_W / 2 - fdf->move->x) &&
		(line->c->x > -IMG_W / 2 - fdf->move->x))
		return (1);
	return (0);
}

static void		print_line_params(t_fdf *fdf, t_line *line)
{
	int		i;
	int		m;

	m = fdf->max;
	i = kostyl(fdf, line, 1);
	if (kostyl_2(fdf, line, i, 1))
		fdf->img.data[i] = line->color2;
	while (line->c->x != line->x2 || line->c->y != line->y2)
	{
		line->c->color = get_color(line);
		i = kostyl(fdf, line, 2);
		if (kostyl_2(fdf, line, i, 2))
			fdf->img.data[i] = line->c->color;
		line->er2 = line->er * 2;
		if (line->er2 > (line->dy * (-1)))
		{
			line->er -= line->dy;
			line->c->x += line->sx;
		}
		if (line->er2 < line->dx)
		{
			line->er += line->dx;
			line->c->y += line->sy;
		}
	}
}

void			set_line_point(t_fdf *fdf, t_pix *p1, t_pix *p2, t_line *line)
{
	line->x1 = p1->x;
	line->x2 = p2->x;
	line->y1 = p1->y;
	line->y2 = p2->y;
	line->z1 = p1->z;
	line->z2 = p2->z;
	line->x1 = line->x1 * fdf->move->zoom;
	line->x2 = line->x2 * fdf->move->zoom;
	line->y1 = line->y1 * fdf->move->zoom;
	line->y2 = line->y2 * fdf->move->zoom;
	line->z1 = line->z1 * fdf->move->zoom;
	line->z2 = line->z2 * fdf->move->zoom;
	if (p1->z != 0)
		line->z1 *= fdf->move->z;
	if (p2->z != 0)
		line->z2 *= fdf->move->z;
	line->color1 = p1->color;
	line->color2 = p2->color;
}

void			print_line(t_fdf *fdf, t_line *line)
{
	rot_x(line, fdf);
	rot_y(line, fdf);
	rot_z(line, fdf);
	iso(line);
	line->dx = abs(line->x2 - line->x1);
	line->dy = abs(line->y2 - line->y1);
	line->sx = (line->x1 < line->x2) ? 1 : -1;
	line->sy = (line->y1 < line->y2) ? 1 : -1;
	line->er = line->dx - line->dy;
	line->er2 = 0;
	line->c->x = line->x1;
	line->c->y = line->y1;
	line->c->color = line->color1;
	print_line_params(fdf, line);
}
