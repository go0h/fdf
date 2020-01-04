/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:10:22 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/12 11:56:40 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf			*create_fdf(void)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf*)malloc(sizeof(t_fdf))))
		ft_exit(NULL, MALLOC_FAILURE);
	fdf->mlx_ptr = NULL;
	fdf->win_ptr = NULL;
	fdf->img_ptr = NULL;
	fdf->size_line = 0;
	fdf->bpp = 0;
	fdf->endian = 0;
	fdf->char_map = NULL;
	fdf->map = NULL;
	fdf->view = NULL;
	fdf->zbuffer = NULL;
	fdf->width = 0;
	fdf->height = 0;
	fdf->colorful = 0;
	fdf->bpp = 0;
	fdf->endian = 0;
	return (fdf);
}

t_view			*create_view(void)
{
	t_view *view;

	if (!(view = (t_view*)malloc(sizeof(t_view))))
		return (NULL);
	view->zoom = 1.0;
	view->style = 0;
	view->relief = 1.0;
	view->off_x = IMG_WIDTH / 2;
	view->off_y = WIN_HEIGHT / 2;
	if (!(view->matrix = matrix_orto()))
	{
		free(view);
		return (NULL);
	}
	return (view);
}

static void		free_view(t_view **view_to_del)
{
	t_view	*view;

	if (*view_to_del)
	{
		free_matrix(&(*view_to_del)->matrix);
		free(*view_to_del);
		*view_to_del = NULL;
	}
}

void			free_fdf(t_fdf **fdf_to_del)
{
	t_fdf	*fdf;

	if (fdf_to_del)
	{
		fdf = *fdf_to_del;
		if (fdf)
		{
			fdf->img_ptr ? mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr) : 0;
			fdf->win_ptr ? mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr) : 0;
			fdf->mlx_ptr ? free(fdf->mlx_ptr) : 0;
			ft_free_arr(fdf->char_map);
			free_vector_map(&fdf->map, fdf->height, fdf->width);
			free_view(&fdf->view);
			free_zbuffer(&fdf->zbuffer);
			free(*fdf_to_del);
		}
		*fdf_to_del = NULL;
	}
}
