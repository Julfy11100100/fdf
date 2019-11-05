/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_iso.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:00:05 by jvoor             #+#    #+#             */
/*   Updated: 2019/10/22 17:22:22 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rot_x(t_line *line, t_fdf *fdf)
{
	int		prev_y1;
	int		prev_y2;

	prev_y1 = line->y1;
	prev_y2 = line->y2;
	line->y1 = cos(fdf->move->angle_x) * prev_y1 +
sin(fdf->move->angle_x) * line->z1;
	line->z1 = -sin(fdf->move->angle_x) * prev_y1 +
cos(fdf->move->angle_x) * line->z1;
	line->y2 = cos(fdf->move->angle_x) * prev_y2 +
sin(fdf->move->angle_x) * line->z2;
	line->z2 = -sin(fdf->move->angle_x) * prev_y2 +
cos(fdf->move->angle_x) * line->z2;
}

void		rot_y(t_line *line, t_fdf *fdf)
{
	int		prev_x1;
	int		prev_x2;

	prev_x1 = line->x1;
	prev_x2 = line->x2;
	line->x1 = prev_x1 * cos(fdf->move->angle_y) +
line->z1 * sin(fdf->move->angle_y);
	line->z1 = -prev_x1 * sin(fdf->move->angle_y) +
line->z1 * cos(fdf->move->angle_y);
	line->x2 = prev_x2 * cos(fdf->move->angle_y) +
line->z2 * sin(fdf->move->angle_y);
	line->z2 = -prev_x2 * sin(fdf->move->angle_y) +
line->z2 * cos(fdf->move->angle_y);
}

void		rot_z(t_line *line, t_fdf *fdf)
{
	int		prev_x1;
	int		prev_x2;
	int		prev_y1;
	int		prev_y2;

	prev_x1 = line->x1;
	prev_x2 = line->x2;
	prev_y1 = line->y1;
	prev_y2 = line->y2;
	line->x1 = cos(fdf->move->angle_z) * prev_x1 -
sin(fdf->move->angle_z) * prev_y1;
	line->y1 = sin(fdf->move->angle_z) * prev_x1 +
cos(fdf->move->angle_z) * prev_y1;
	line->x2 = cos(fdf->move->angle_z) * prev_x2 -
sin(fdf->move->angle_z) * prev_y2;
	line->y2 = sin(fdf->move->angle_z) * prev_x2 +
cos(fdf->move->angle_z) * prev_y2;
}

void		iso(t_line *line)
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
