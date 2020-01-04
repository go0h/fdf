/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 22:02:41 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/12 11:38:10 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		margin(t_fdf *fdf)
{
	int		margin_x;
	int		margin_y;
	int		i;
	int		j;

	margin_x = (IMG_WIDTH - (2 * MARGIN)) / (fdf->width - 1);
	margin_y = (IMG_HEIGHT - (2 * MARGIN)) / (fdf->height - 1);
	fdf->view->off_x = IMG_WIDTH / 2 + (fdf->width % 2 ? 0 : margin_x / 2);
	fdf->view->off_y = IMG_HEIGHT / 2 + (fdf->height % 2 ? 0 : margin_y / 2);
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->map[i][j].x = fdf->map[i][j].x * margin_x;
			fdf->map[i][j].y = fdf->map[i][j].y * margin_y;
			if (fdf->map[i][j].z > 0)
				fdf->map[i][j].z += ((margin_x + margin_y) / 2);
			else if (fdf->map[i][j].z < 0)
				fdf->map[i][j].z -= ((margin_x + margin_y) / 2);
			++j;
		}
		++i;
	}
}

void			initialize(t_fdf *fdf)
{
	if (!(fdf->mlx_ptr = mlx_init()))
		ft_exit(&fdf, MALLOC_FAILURE);
	if (!(fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
	"Fil de fer")))
		ft_exit(&fdf, MALLOC_FAILURE);
	if (!(fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, IMG_WIDTH, IMG_HEIGHT)))
		ft_exit(&fdf, MALLOC_FAILURE);
	if (!(fdf->img_str = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp,\
	&fdf->size_line, &fdf->endian)))
		ft_exit(&fdf, MALLOC_FAILURE);
	if (!(fdf->view = create_view()))
		ft_exit(&fdf, MALLOC_FAILURE);
	if (!(fdf->zbuffer = create_zbuffer()))
		ft_exit(&fdf, MALLOC_FAILURE);
	margin(fdf);
}
