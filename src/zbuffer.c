/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zbuffer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:35:46 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/12 11:19:59 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_zbuffer(int ***zbuffer)
{
	int		i;
	int		**temp;

	if (zbuffer && *zbuffer)
	{
		i = 0;
		temp = *zbuffer;
		while (i < IMG_HEIGHT)
		{
			free(temp[i]);
			++i;
		}
		free(*zbuffer);
		*zbuffer = NULL;
	}
}

int			**create_zbuffer(void)
{
	int		i;
	int		**zbuffer;

	i = 0;
	if (!(zbuffer = (int**)malloc(sizeof(int*) * IMG_HEIGHT)))
		return (NULL);
	while (i < IMG_HEIGHT)
	{
		if (!(zbuffer[i] = (int*)malloc(sizeof(int) * IMG_WIDTH)))
		{
			free_zbuffer(&zbuffer);
			return (NULL);
		}
		++i;
	}
	drop_zbuffer(zbuffer);
	return (zbuffer);
}

void		drop_zbuffer(int **zbuffer)
{
	int		i;
	int		j;

	i = 0;
	while (i < IMG_HEIGHT)
	{
		j = 0;
		while (j < IMG_WIDTH)
		{
			zbuffer[i][j] = SHORT_MIN;
			++j;
		}
		++i;
	}
}
