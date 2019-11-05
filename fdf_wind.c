/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 16:51:42 by mmark             #+#    #+#             */
/*   Updated: 2019/10/16 13:21:39 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_message(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 150, 50, 0xFF0000,
	"'SPACE' -> reset pic");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 150, 150, 0xFF0000,
	"'+' ; '-' -> ZOOM");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 150, 250, 0xFF0000,
	"'/' ; '*' -> Z");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 150, 350, 0xFF0000,
	"'WASD' -> MOOVE");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 150, 450, 0xFF0000,
	"'ESC' -> EXIT");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 150, 550, 0xFF0000,
	"'G'/'B' -> rotate X");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 150, 650, 0xFF0000,
	"'H'/'N' -> rotate Y");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 150, 750, 0xFF0000,
	"'J'/'M' -> rotate Z");
}

t_fdf		*fdf_new(int ww, int wh, char **array)
{
	t_fdf		*fdf;
	t_move		*move;
	t_table		*table;

	fdf = (t_fdf*)malloc(sizeof(t_fdf));
	table = get_table(array);
	move = (t_move*)malloc(sizeof(t_move));
	fdf->table = table;
	fdf->move = move;
	fdf->move->angle_x = 0;
	fdf->move->angle_y = 0;
	fdf->move->angle_z = 0;
	fdf->move->zoom = 1;
	fdf->move->x = 0;
	fdf->move->y = 0;
	fdf->move->z = 1;
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, ww, wh, "FDF");
	fdf->img.img_ptr = mlx_new_image(fdf->mlx_ptr, IMG_W, IMG_H);
	fdf->img.data = (int *)mlx_get_data_addr(fdf->img.img_ptr,
		&fdf->img.bpr, &fdf->img.size_line, &fdf->img.endian);
	fdf->max = IMG_H * IMG_W * 4;
	del_array(&array);
	return (fdf);
}

t_line		*line_new(void)
{
	t_line	*line;
	t_pix	*c;

	line = (t_line *)malloc(sizeof(t_line));
	c = (t_pix *)malloc(sizeof(t_pix));
	line->c = c;
	return (line);
}

void		redraw_line(t_fdf *fdf)
{
	t_line	*line;

	line = line_new();
	ft_memset(fdf->img.data, 0x000000, fdf->max);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	print(fdf, line);
	mlx_put_image_to_window(fdf->mlx_ptr,
		fdf->win_ptr, fdf->img.img_ptr, 0, 0);
	fdf_message(fdf);
	del_line(&line);
}
