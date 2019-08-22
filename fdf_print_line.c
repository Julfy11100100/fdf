/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmark <mmark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 13:36:12 by mmark             #+#    #+#             */
/*   Updated: 2019/08/14 20:44:52 by mmark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

static void		iso(t_line *line)
{
	int			prev_x1;
	int			prev_y1;
	int			prev_x2;
	int			prev_y2;

	prev_x1 = line->x1;
	prev_x2 = line->x2;
	prev_y1 = line->y1;
	prev_y2 = line->y2;
	line->x1 = (prev_x1 - prev_y1) * cos(0.523599);
	line->y1 = (prev_x1 + prev_y1) * sin(0.523599) - line->z1;
	line->x2 = (prev_x2 - prev_y2) * cos(0.523599);
	line->y2 = (prev_x2 + prev_y2) * sin(0.523599) - line->z2;
}

static void		print_line_params(t_fdf *fdf, t_line *line)
{
	int		i;

	i = line->y2 * IMG_W + line->x2;
	if (line->y2 > 0 && line->x2 > 0 &&
		line->y2 < IMG_H && line->x2 < IMG_W && i < fdf->max)
		fdf->img.data[i] = line->color2;
	while (line->c->x != line->x2 || line->c->y != line->y2)
	{
		line->c->color = get_color(line);
		i = line->c->y * IMG_W + line->c->x;
		if (line->c->y > 0 && line->c->x > 0 &&
			line->c->y < IMG_H && line->c->x < IMG_W && i < fdf->max)
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
	line->x1 = p1->x * fdf->move->zoom + fdf->move->x;
	line->x2 = p2->x * fdf->move->zoom + fdf->move->x;
	line->y1 = p1->y * fdf->move->zoom + fdf->move->y;
	line->y2 = p2->y * fdf->move->zoom + fdf->move->y;
	line->z1 = p1->z * fdf->move->zoom;
	line->z2 = p2->z * fdf->move->zoom;
	if (p1->z != 0)
		line->z1 *= fdf->move->z;
	if (p2->z != 0)
		line->z2 *= fdf->move->z;
	line->color1 = p1->color;
	line->color2 = p2->color;
}

void			print_line(t_fdf *fdf, t_line *line)
{
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
