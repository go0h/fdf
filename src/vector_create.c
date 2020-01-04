/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 21:49:47 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/12 12:25:26 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		max_height(t_fdf *fdf)
{
	int		i;
	int		j;
	int		max_height;

	max_height = -2147483648;
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			if (fdf->map[i][j].z > max_height)
				max_height = fdf->map[i][j].z;
			j++;
		}
		i++;
	}
	return (max_height);
}

static int		min_height(t_fdf *fdf)
{
	int		i;
	int		j;
	int		min_height;

	min_height = 2147483647;
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			if (fdf->map[i][j].z < min_height)
				min_height = fdf->map[i][j].z;
			j++;
		}
		i++;
	}
	return (min_height);
}

static void		add_height_and_width(t_fdf *fdf, char *map)
{
	char	**line;

	if (!(fdf->char_map = ft_strsplit(map, '\n')))
		ft_exit(&fdf, MALLOC_FAILURE);
	fdf->height = ft_len_arr(fdf->char_map);
	if (!(line = ft_strsplit(fdf->char_map[0], ' ')))
		ft_exit(&fdf, MALLOC_FAILURE);
	fdf->width = ft_len_arr(line);
	ft_free_arr(line);
	if (!(fdf->map = (t_vector**)malloc(sizeof(t_vector*) * fdf->height)))
		ft_exit(&fdf, MALLOC_FAILURE);
}

void			free_vector_map(t_vector ***map_to_del, int height, int width)
{
	int			i;
	t_vector	**map;

	i = 0;
	if (*map_to_del)
	{
		map = *map_to_del;
		while (i < height)
		{
			free(map[i]);
			++i;
		}
		free(map);
		*map_to_del = NULL;
	}
}

void			create_vector_map(t_fdf *fdf, char *char_map)
{
	char	**line;
	int		i;
	int		j;

	add_height_and_width(fdf, char_map);
	i = 0;
	while (i < fdf->height)
	{
		if (!(fdf->map[i] = (t_vector*)malloc(sizeof(t_vector) * fdf->width)))
			ft_exit(&fdf, MALLOC_FAILURE);
		if (!(line = ft_strsplit(fdf->char_map[i], ' '))\
		&& ft_len_arr(line) != fdf->width)
			ft_exit(&fdf, LINE_LENGTHS);
		j = 0;
		while (j < fdf->width)
		{
			point_height_color(fdf, i, j, line[j]);
			++j;
		}
		ft_free_arr(line);
		++i;
	}
	fdf->max_h = max_height(fdf);
	fdf->min_h = min_height(fdf);
}
