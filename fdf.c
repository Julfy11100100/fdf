/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmark <mmark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 15:23:27 by mmark             #+#    #+#             */
/*   Updated: 2019/08/14 20:47:52 by mmark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	t_line	*line;
	char	**array;

	if (argc != 2)
	{
		ft_putstr("Usage:./fdf [file.fdf]\n");
		return (0);
	}
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
