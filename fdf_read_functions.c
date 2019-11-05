/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 20:23:26 by mmark             #+#    #+#             */
/*   Updated: 2019/10/22 16:56:48 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		**get_array(char *file)
{
	int		i;
	char	*line;
	char	**table;
	int		fd;

	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		i++;
		ft_strdel(&line);
	}
	table = (char**)malloc(sizeof(char*) * i + 1);
	table[i] = NULL;
	i = -1;
	close(fd);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		table[++i] = ft_strdup(line);
		ft_strdel(&line);
	}
	close(fd);
	return (table);
}
