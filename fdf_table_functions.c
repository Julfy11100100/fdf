/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_table_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 22:40:23 by mmark             #+#    #+#             */
/*   Updated: 2019/10/21 18:42:54 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

static int	get_table_params(t_table *table, char **array)
{
	int		i;
	char	**buf;

	i = 0;
	buf = ft_strsplit(array[0], ' ');
	while (buf[i])
		i++;
	del_array(&buf);
	table->w = i;
	i = 0;
	while (array[i])
		i++;
	table->h = i;
	return (0);
}

static int	get_table_map(t_table *table, char **array)
{
	char	**buf;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < table->h)
	{
		buf = ft_strsplit(array[i], ' ');
		j = 0;
		while (j < table->w)
		{
			table->map[k]->x = j;
			table->map[k]->y = i;
			table->map[k]->z = (ft_atoi_h(buf[j]));
			table->map[k]->color = pix_color(buf[j], table->map[k]->z);
			j++;
			k++;
		}
		del_array(&buf);
		i++;
	}
	return (0);
}

t_table		*get_table(char **array)
{
	t_table	*table;
	t_pix	**map;
	int		i;
	int		j;

	table = (t_table *)malloc(sizeof(t_table));
	get_table_params(table, array);
	i = table->w * table->h;
	j = 0;
	map = (t_pix **)malloc(sizeof(t_pix *) * i);
	while (j < i)
	{
		map[j] = (t_pix *)malloc(sizeof(t_pix));
		j++;
	}
	table->map = map;
	get_table_map(table, array);
	return (table);
}
