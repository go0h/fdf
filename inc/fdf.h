/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:51:07 by astripeb          #+#    #+#             */
/*   Updated: 2020/01/04 12:46:50 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libftprintf.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include "color.h"
# include "buttons.h"

# ifdef __linux__
# define WIN_WIDTH	1200
# define WIN_HEIGHT	800
# define IMG_WIDTH	900
# define IMG_HEIGHT	800
# define MARGIN		50
# define INDENT		300
# else
# define WIN_WIDTH	2800
# define WIN_HEIGHT	1500
# define IMG_WIDTH	2400
# define IMG_HEIGHT	1500
# define MARGIN		100
# define INDENT		400
# endif

# define USAGE			100
# define LINE_LENGTHS	101
# define INVALID_HEIGHT	102
# define INVALID_COLOR	103
# define INVALID_INT	104

# define AXIS_X			7
# define AXIS_Y			8
# define AXIS_Z			9

# define SHORT_MIN		-32768

typedef union		u_color
{
	struct			s_rgb
	{
		unsigned char	blue:8;
		unsigned char	green:8;
		unsigned char	red:8;
	}				t_rgb;
	unsigned int	color;
}					t_color;

typedef struct		s_vector
{
	int				x;
	int				y;
	int				z;
	union u_color	c;
}					t_vector;

typedef struct		s_delta
{
	int				dx;
	int				dy;
	int				dz;
	int				length_x;
	int				length_y;
	int				length_z;
	int				length;
}					t_delta;

typedef struct		s_view
{
	int				off_x;
	int				off_y;
	char			style;
	float			**matrix;
	float			zoom;
	float			relief;
	t_vector		a;
	t_vector		b;
}					t_view;

typedef struct		s_fdf
{
	char			**char_map;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_str;
	int				size_line;
	int				width;
	int				height;
	int				colorful;
	int				min_h;
	int				max_h;
	int				bpp;
	int				endian;
	struct s_vector	**map;
	struct s_view	*view;
	int				auto_color;
	int				**zbuffer;
}					t_fdf;

void				ft_exit(t_fdf **fdf, int err);

/*
** CREATE FDF STRUCTURE
*/

t_fdf				*create_fdf(void);

t_view				*create_view(void);

void				free_fdf(t_fdf **fdf_to_del);

void				free_vector_map(t_vector ***map_to_del, int height,\
					int width);

void				create_vector_map(t_fdf *fdf, char *char_map);

void				point_height_color(t_fdf *fdf, int x, int y, char *point);

void				initialize(t_fdf *fdf);

/*
**  DRAW FUNCTIONS
*/

void				draw_line(t_fdf *fdf, t_vector a, t_vector b);

void				view(t_fdf *fdf);

void				put_legend(void *mlx_ptr, void *win_ptr, void *img_ptr);

/*
**  HOOOOOOOOOKS
*/

int					key_hook(int key_code, void *param);

int					mouse_hook(int button, int x, int y, void *param);

void				ft_fdf(t_fdf *fdf);

/*
**  ACTIONS
*/

void				isometric(t_fdf *fdf);

void				flatten(t_fdf *fdf);

void				profile(float **matrix);

/*
**  WAKE UP NEO, MATRIX HAS YOU
*/

void				free_matrix(float ***matrix_to_del);

float				**create_matrix(void);

float				**matrix_x(float alpha);

float				**matrix_y(float alpha);

float				**matrix_z(float alpha);

float				**multiplication(float **cur, float **matrix);

float				**matrix_orto(void);

void				change_matrix(t_fdf *fdf, float alpha, char axis);

/*
**	COLORS
*/

unsigned int		change_color(t_fdf *fdf, t_vector *src);

unsigned char		gradient_red(t_fdf *fdf, t_vector *cur);

unsigned char		gradient_green(t_fdf *fdf, t_vector *cur);

unsigned char		gradient_blue(t_fdf *fdf, t_vector *cur);

unsigned char		mix_red(t_fdf *fdf, t_vector *cur);

unsigned char		mix_green(t_fdf *fdf, t_vector *cur);

unsigned char		mix_blue(t_fdf *fdf, t_vector *cur);

/*
**	Z-BUFFER
*/

void				free_zbuffer(int ***zbuffer);

int					**create_zbuffer(void);

void				drop_zbuffer(int **zbuffer);

/*
**  UTILITY (delete before evaluation)
*/

void				print_matrix(float **matrix);

void				print_z(short **zbuffer);

#endif
