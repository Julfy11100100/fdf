/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 22:57:47 by mmark             #+#    #+#             */
/*   Updated: 2019/10/02 15:39:51 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double		percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int			get_light(int start, int end, double persentage)
{
	return ((int)((1 - persentage) * start + persentage * end));
}

int					get_color(t_line *line)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (line->c->color == line->color2)
		return (line->c->color);
	if (line->dx > line->dy)
		percentage = percent(line->x1, line->x2, line->c->x);
	else
		percentage = percent(line->y1, line->y2, line->c->y);
	red = get_light((line->color1 >> 16) & 0xFF,
	(line->color2 >> 16) & 0xFF, percentage);
	green = get_light((line->color1 >> 8) & 0xFF,
	(line->color2 >> 8) & 0xFF, percentage);
	blue = get_light(line->color1 & 0xFF, line->color2 & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int					pix_color(char *str, int z)
{
	if (ft_strchr(str, ',') != 0)
		return (ft_atoi_h(1 + ft_strchr(str, ',')));
	else
	{
		if (z <= 0)
			return (0x0000FF);
		if (0 < z && z <= 4)
			return (0x0FFF0F);
		if (5 < z && z <= 6)
			return (0x00FF00);
		if (7 < z && z < 11)
			return (0xE0E0E0);
		if (z >= 11)
			return (0xFFFFFF);
	}
	return (0xFF0000);
}
