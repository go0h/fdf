/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:41:56 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/12 11:09:18 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_color	get_color(t_vector a, t_vector b, int cur, int len)
{
	float	coef;
	t_color	c;

	coef = (float)cur / len;
	c.t_rgb.red = (char)((1 - coef) * b.c.t_rgb.red + coef *\
	a.c.t_rgb.red);
	c.t_rgb.green = (char)((1 - coef) * b.c.t_rgb.green + coef *\
	a.c.t_rgb.green);
	c.t_rgb.blue = (char)((1 - coef) * b.c.t_rgb.blue + coef *\
	a.c.t_rgb.blue);
	return (c);
}

static void		pixel_put_to_str(t_fdf *fdf, t_vector v)
{
	int i;

	if ((v.x >= 0 && v.x < IMG_WIDTH) && (v.y >= 0 && v.y < IMG_HEIGHT))
	{
		if (fdf->zbuffer[v.y][v.x] < v.z)
		{
			fdf->zbuffer[v.y][v.x] = v.z;
			i = v.y * fdf->size_line + v.x * sizeof(int);
			fdf->img_str[i] = v.c.t_rgb.blue;
			fdf->img_str[++i] = v.c.t_rgb.green;
			fdf->img_str[++i] = v.c.t_rgb.red;
		}
	}
}

static void		draw_along_x(t_fdf *fdf, t_vector a, t_vector b, t_delta delta)
{
	t_vector	v;
	int			d;
	int			z;

	v = a;
	z = -delta.length_z;
	d = -delta.length_x;
	while (delta.length--)
	{
		v.c = get_color(a, b, delta.length, ft_abs(a.x - b.x));
		pixel_put_to_str(fdf, v);
		v.x += delta.dx;
		d += 2 * delta.length_y;
		z += 2 * delta.length_z;
		if (d > 0)
		{
			d -= 2 * delta.length_x;
			v.y += delta.dy;
		}
		if (z > 0)
		{
			z -= 2 * delta.length_z;
			v.z += delta.dz;
		}
	}
}

static void		draw_along_y(t_fdf *fdf, t_vector a, t_vector b, t_delta delta)
{
	t_vector	v;
	int			d;
	int			z;

	v = a;
	d = -delta.length_y;
	z = -delta.length_z;
	while (delta.length--)
	{
		v.c = get_color(a, b, delta.length, ft_abs(a.y - b.y));
		pixel_put_to_str(fdf, v);
		v.y += delta.dy;
		d += 2 * delta.length_x;
		z += 2 * delta.length_z;
		if (d > 0)
		{
			d -= 2 * delta.length_y;
			v.x += delta.dx;
		}
		if (z > 0)
		{
			z -= 2 * delta.length_z;
			v.z += delta.dz;
		}
	}
}

void			draw_line(t_fdf *fdf, t_vector a, t_vector b)
{
	t_delta delta;

	delta.dx = (b.x - a.x >= 0 ? 1 : -1);
	delta.dy = (b.y - a.y >= 0 ? 1 : -1);
	delta.dz = (b.z - a.z >= 0 ? 1 : -1);
	delta.length_x = abs(b.x - a.x);
	delta.length_y = abs(b.y - a.y);
	delta.length_z = abs(b.z - a.z);
	delta.length = delta.length_x > delta.length_y ?\
	delta.length_x + 1 : delta.length_y + 1;
	if (delta.length == 0)
		pixel_put_to_str(fdf, a);
	else
	{
		if (delta.length_y <= delta.length_x)
			draw_along_x(fdf, a, b, delta);
		else
			draw_along_y(fdf, a, b, delta);
	}
}
