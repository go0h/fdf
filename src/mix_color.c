/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:28:28 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/12 12:08:21 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_biggest(unsigned char x, unsigned char a, unsigned char b)
{
	if (x > a && x > b)
		return (1);
	return (0);
}

unsigned char	mix_red(t_fdf *fdf, t_vector *cur)
{
	unsigned char	red;
	float			k;

	if (fdf->view->style == 1)
		red = cur->c.t_rgb.blue;
	else if (fdf->view->style == 2)
		red = cur->c.t_rgb.green;
	else if (fdf->view->style == 3)
		red = 255 - cur->c.t_rgb.red;
	else if (fdf->view->style == 4)
		red = cur->c.t_rgb.red * 2;
	else if (fdf->view->style == 5)
		red = cur->c.t_rgb.red / 2;
	else if (fdf->view->style == 6)
	{
		k = (float)cur->c.t_rgb.red / 255;
		red = ft_biggest(cur->c.t_rgb.red, cur->c.t_rgb.blue,\
		cur->c.t_rgb.green) ? 200 + (55 * k) : 0;
	}
	return (red);
}

unsigned char	mix_green(t_fdf *fdf, t_vector *cur)
{
	unsigned char	green;
	float			k;

	if (fdf->view->style == 1)
		green = cur->c.t_rgb.red;
	else if (fdf->view->style == 2)
		green = cur->c.t_rgb.blue;
	else if (fdf->view->style == 3)
		green = 255 - cur->c.t_rgb.green;
	else if (fdf->view->style == 4)
		green = cur->c.t_rgb.green * 2;
	else if (fdf->view->style == 5)
		green = cur->c.t_rgb.green / 2;
	else if (fdf->view->style == 6)
	{
		k = (float)cur->c.t_rgb.red / 255;
		green = ft_biggest(cur->c.t_rgb.green, cur->c.t_rgb.blue,\
		cur->c.t_rgb.red) ? 200 + (55 * k) : 0;
	}
	return (green);
}

unsigned char	mix_blue(t_fdf *fdf, t_vector *cur)
{
	unsigned char	blue;
	float			k;

	if (fdf->view->style == 1)
		blue = cur->c.t_rgb.green;
	else if (fdf->view->style == 2)
		blue = cur->c.t_rgb.red;
	else if (fdf->view->style == 3)
		blue = 255 - cur->c.t_rgb.blue;
	else if (fdf->view->style == 4)
		blue = cur->c.t_rgb.blue * 2;
	else if (fdf->view->style == 5)
		blue = cur->c.t_rgb.blue * 2;
	else if (fdf->view->style == 6)
	{
		k = (float)cur->c.t_rgb.red / 255;
		blue = ft_biggest(cur->c.t_rgb.blue, cur->c.t_rgb.green,\
		cur->c.t_rgb.red) ? 200 + (55 * k) : 0;
	}
	return (blue);
}
