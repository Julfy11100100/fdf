/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions_01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:54:07 by jvoor             #+#    #+#             */
/*   Updated: 2019/10/16 13:44:02 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	rebuild(t_fdf *fdf)
{
	fdf->move->angle_x = 0;
	fdf->move->angle_y = 0;
	fdf->move->angle_z = 0;
	fdf->move->x = 0;
	fdf->move->y = 0;
	fdf->move->z = 1;
	fdf->move->zoom = 1;
	redraw_line(fdf);
	return (0);
}

static int	rotate(t_fdf *fdf, int key)
{
	if (key == 5 || key == 11)
		fdf->move->angle_x += (key == 5) ? 0.087 : -0.087;
	if (key == 4 || key == 45)
		fdf->move->angle_y += (key == 4) ? 0.087 : -0.087;
	if (key == 38 || key == 46)
		fdf->move->angle_z += (key == 38) ? 0.087 : -0.087;
	redraw_line(fdf);
	return (0);
}

int			key_press_01(int key, t_fdf *fdf)
{
	if (key == 5 || key == 11 || key == 4 || key == 45
	|| key == 38 || key == 46)
		rotate(fdf, key);
	if (key == 49)
		rebuild(fdf);
	return (0);
}
