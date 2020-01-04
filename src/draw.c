/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:14:12 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/12 11:53:20 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		isometric(t_fdf *fdf)
{
	int		margin_x;
	int		margin_y;

	margin_x = fdf->map[0][1].x - fdf->map[0][0].x;
	margin_y = fdf->map[1][0].y - fdf->map[0][0].y;
	free_matrix(&fdf->view->matrix);
	if (!(fdf->view->matrix = matrix_x(0.523599)))
		ft_exit(&fdf, MALLOC_FAILURE);
	change_matrix(fdf, 0.785398, AXIS_Z);
	fdf->view->off_x = IMG_WIDTH / 2 + (fdf->width % 2 ? 0 : margin_x / 2);
	fdf->view->off_y = IMG_HEIGHT / 2 + (fdf->height % 2 ? 0 : margin_y / 2);
	fdf->view->zoom = 0.7;
}

void		flatten(t_fdf *fdf)
{
	int		margin_x;
	int		margin_y;

	margin_x = fdf->map[0][1].x - fdf->map[0][0].x;
	margin_y = fdf->map[1][0].y - fdf->map[0][0].y;
	free_matrix(&fdf->view->matrix);
	if (!(fdf->view->matrix = matrix_orto()))
		ft_exit(&fdf, MALLOC_FAILURE);
	fdf->view->off_x = IMG_WIDTH / 2 + (fdf->width % 2 ? 0 : margin_x / 2);
	fdf->view->off_y = IMG_HEIGHT / 2 + (fdf->height % 2 ? 0 : margin_y / 2);
	fdf->view->zoom = 1.0;
}

void		profile(float **matrix)
{
	matrix[0][0] = 1.0;
	matrix[0][1] = 0.0;
	matrix[0][2] = matrix[0][1];
	matrix[1][0] = matrix[0][1];
	matrix[1][1] = matrix[0][1];
	matrix[1][2] = -matrix[0][0];
	matrix[2][0] = matrix[0][1];
	matrix[2][1] = matrix[0][0];
	matrix[2][2] = matrix[0][1];
}

t_vector	apply_view(t_fdf *fdf, t_vector *src)
{
	float		**mtx;
	t_vector	a;

	mtx = fdf->view->matrix;
	a.x = src->x * mtx[0][0] + src->y * mtx[0][1] + src->z * mtx[0][2]\
	* fdf->view->relief;
	a.y = src->x * mtx[1][0] + src->y * mtx[1][1] + src->z * mtx[1][2]\
	* fdf->view->relief;
	a.z = src->x * mtx[2][0] + src->y * mtx[2][1] + src->z * mtx[2][2]\
	* fdf->view->relief;
	a.x *= fdf->view->zoom;
	a.y *= fdf->view->zoom;
	a.x += fdf->view->off_x;
	a.y += fdf->view->off_y;
	a.c.color = fdf->view->style ? change_color(fdf, src) : src->c.color;
	return (a);
}

void		view(t_fdf *fdf)
{
	int			i;
	int			j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->view->a = apply_view(fdf, &fdf->map[i][j]);
			if (i)
			{
				fdf->view->b = apply_view(fdf, &fdf->map[i - 1][j]);
				draw_line(fdf, fdf->view->a, fdf->view->b);
			}
			if (j)
			{
				fdf->view->b = apply_view(fdf, &fdf->map[i][j - 1]);
				draw_line(fdf, fdf->view->a, fdf->view->b);
			}
			++j;
		}
		++i;
	}
	drop_zbuffer(fdf->zbuffer);
}
