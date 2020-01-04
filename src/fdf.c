/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:50:53 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/12 12:36:35 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*map;
	t_fdf	*fdf;

	argc != 2 ? ft_exit(NULL, USAGE) : 0;
	if ((fd = open(argv[1], O_RDONLY)) < 1)
		ft_exit(NULL, 0);
	fdf = create_fdf();
	if (!(map = read_from_file_to_var(fd)))
		ft_exit(NULL, MALLOC_FAILURE);
	create_vector_map(fdf, map);
	initialize(fdf);
	put_legend(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr);
	ft_fdf(fdf);
	free_fdf(&fdf);
	free(map);
	close(fd);
	return (0);
}

void	ft_fdf(t_fdf *fdf)
{
	view(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr,\
	INDENT, 0);
	mlx_hook(fdf->win_ptr, 2, 0, &key_hook, fdf);
	mlx_mouse_hook(fdf->win_ptr, &mouse_hook, (void*)fdf);
	mlx_hook(fdf->win_ptr, 17, 0, (int(*)())exit, (void*)fdf);
	mlx_loop(fdf->mlx_ptr);
}
