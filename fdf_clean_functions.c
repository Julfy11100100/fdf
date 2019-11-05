/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_clean_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:36:08 by mmark             #+#    #+#             */
/*   Updated: 2019/10/22 14:52:04 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		del_pix(t_pix **pix)
{
	t_pix		*pb;

	if (pix && *pix)
	{
		pb = *pix;
		pb->x = 0;
		pb->y = 0;
		pb->z = 0;
		pb->color = 0;
		free(pb);
		*pix = NULL;
	}
}

void			del_map_pix(t_pix ***map, int count)
{
	t_pix		**bm;
	int			i;

	bm = *map;
	i = 0;
	while (i < count)
	{
		del_pix(&(bm[i]));
		i++;
	}
	free(bm);
	map = NULL;
}

void			del_fdf(t_fdf **fdf)
{
	t_fdf		*bdf;

	bdf = *fdf;
	if (fdf && *fdf)
	{
		bdf->mlx_ptr = NULL;
		bdf->win_ptr = NULL;
		bdf->max = 0;
		del_table(&bdf->table);
		bdf->table = NULL;
		bdf->move->x = 0;
		bdf->move->y = 0;
		bdf->move->z = 0;
		bdf->move->zoom = 0;
		free(bdf->move);
		bdf->move = NULL;
		bdf->img.bpr = 0;
		bdf->img.size_line = 0;
		bdf->img.endian = 0;
		bdf->img.img_ptr = NULL;
		free(bdf->img.data);
		bdf->img.data = NULL;
		free(bdf);
		*fdf = NULL;
	}
}

void			del_line(t_line **line)
{
	t_line		*bl;

	bl = *line;
	bl->color1 = 0;
	bl->color2 = 0;
	bl->dx = 0;
	bl->dy = 0;
	bl->er2 = 0;
	bl->er = 0;
	bl->sx = 0;
	bl->sy = 0;
	del_pix(&(bl->c));
	free(bl);
	line = NULL;
}

void			del_array(char ***array)
{
	int			i;
	char		**parray;

	if (array && *array && **array)
	{
		parray = *array;
		i = 0;
		while (parray[i])
		{
			ft_strdel(&(parray[i]));
			i++;
		}
		free(parray);
		*array = NULL;
	}
}
