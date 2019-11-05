/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 15:23:27 by mmark             #+#    #+#             */
/*   Updated: 2019/10/24 14:19:53 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		checks(int argc, char **argv)
{
	int			fd;
	char		*str;

	str = NULL;
	fd = open(argv[1], O_RDONLY);
	if (read(fd, str, 1) == 0)
	{
		ft_putstr("Invalid file\n");
		close(fd);
		return (-1);
	}
	if (fd == -1)
	{
		ft_putstr("File is not exist\n");
		close(fd);
		return (-1);
	}
	if (argc != 2)
	{
		ft_putstr("Usage:./fdf [file.fdf]\n");
		close(fd);
		return (-1);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_fdf		*fdf;
	t_line		*line;
	char		**array;

	if (checks(argc, argv) == -1)
		return (0);
	array = get_array(argv[1]);
	if (!(is_valid(array) && name_valid(argv[1])))
	{
		ft_putstr("Invalid file\n");
		return (0);
	}
	fdf = fdf_new(WIN_W, WIN_H, array);
	line = line_new();
	print(fdf, line);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.img_ptr, 0, 0);
	fdf_message(fdf);
	mlx_hook(fdf->win_ptr, 2, 0, key_press, fdf);
	mlx_loop(fdf->mlx_ptr);
	del_fdf(&fdf);
	del_line(&line);
	return (0);
}
