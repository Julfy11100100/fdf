/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmark <mmark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:46:16 by mmark             #+#    #+#             */
/*   Updated: 2019/08/14 16:22:42 by mmark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print(t_fdf *fdf, t_line *line)
{
	int i;
	int j;
	int w;

	w = fdf->table->w;
	i = -1;
	while (++i < fdf->table->h)
	{
		j = -1;
		while (++j < w)
		{
			if (j < (w - 1))
			{
				set_line_point(fdf, fdf->table->map[i * w + j],
					fdf->table->map[i * w + j + 1], line);
				print_line(fdf, line);
			}
			if (i < (fdf->table->h - 1))
			{
				set_line_point(fdf, fdf->table->map[i * w + j],
					fdf->table->map[(i + 1) * w + j], line);
				print_line(fdf, line);
			}
		}
	}
}
