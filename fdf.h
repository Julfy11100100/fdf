/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 13:34:27 by mmark             #+#    #+#             */
/*   Updated: 2019/10/22 17:22:28 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define IMG_W 1920
# define IMG_H 1080
# define WIN_W 1920
# define WIN_H 1080

typedef struct	s_move
{
	float		x;
	float		y;
	float		z;
	int			zoom;
	float		angle_x;
	float		angle_y;
	float		angle_z;
}				t_move;

typedef struct	s_pix
{
	float		x;
	float		y;
	float		z;
	int			color;
}				t_pix;

typedef struct	s_table
{
	t_pix		**map;
	int			w;
	int			h;
}				t_table;

typedef struct	s_line
{
	t_pix		*c;
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	float		z1;
	float		z2;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			er;
	int			er2;
	int			color1;
	int			color2;
}				t_line;

typedef struct	s_img
{
	void		*img_ptr;
	int			bpr;
	int			size_line;
	int			endian;
	int			*data;
}				t_img;

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_move		*move;
	t_table		*table;
	t_img		img;
	int			max;
}				t_fdf;

void			set_line_point(t_fdf *fdf, t_pix *p1, t_pix *p2, t_line *line);
void			print_line(t_fdf *fdf, t_line *line);

t_fdf			*fdf_new(int ww, int wh, char **array);
void			fdf_message(t_fdf *fdf);
t_line			*line_new(void);
void			redraw_line(t_fdf *fdf);

int				deal_key(int key, t_fdf *fdf);
int				key_press(int key, t_fdf *fdf);
int				key_press_01(int key, t_fdf *fdf);

void			del_fdf(t_fdf **fdf);
void			del_array(char ***array);
void			del_line(t_line **line);
void			del_table(t_table **table);
void			del_map_pix(t_pix ***map, int count);

char			**get_array(char *file);

t_table			*get_table(char **array);

void			print(t_fdf *fdf, t_line *line);

int				get_color(t_line *line);
int				pix_color(char *str, int z);

int				ft_atoi_h(char *str);

int				mouse_release(int button, int x, int y, t_fdf *fdf);

int				is_valid(char **str);
int				name_valid(char *name);

void			iso(t_line *line);
void			rot_x(t_line *line, t_fdf *fdf);
void			rot_y(t_line *line, t_fdf *fdf);
void			rot_z(t_line *line, t_fdf *fdf);

#endif
