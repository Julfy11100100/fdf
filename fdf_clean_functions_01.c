/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_clean_functions_01.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 23:20:23 by jvoor             #+#    #+#             */
/*   Updated: 2019/08/14 23:21:05 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		del_table(t_table **table)
{
	t_table *bt;
	int		i;

	if (table && *table)
	{
		bt = *table;
		i = bt->h * bt->w;
		if (bt->map)
			del_map_pix(&(bt->map), i);
		bt->w = 0;
		bt->h = 0;
		bt->map = 0;
		free(bt->map);
		free(bt);
		table = NULL;
	}
}
