/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:27:41 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/12 12:37:52 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned char	gradient_red(t_fdf *fdf, t_vector *cur)
{
	char			style;
	unsigned char	red;
	float			coef;

	style = fdf->view->style;
	coef = (float)(cur->z - fdf->min_h) / (fdf->max_h - fdf->min_h);
	if (style == 1 || style == 4 || style == 5)
		red = 0xFF;
	else if (style == 2 || style == 3 || style == 6)
		red = (int)(0xFF * coef);
	return (red);
}

unsigned char	gradient_green(t_fdf *fdf, t_vector *cur)
{
	char			style;
	unsigned char	green;
	float			coef;

	style = fdf->view->style;
	coef = (float)(cur->z - fdf->min_h) / (fdf->max_h - fdf->min_h);
	if (style == 2 || style == 5 || style == 6)
		green = 0xFF;
	else if (style == 1 || style == 3 || style == 4)
		green = (int)(0xFF * coef);
	return (green);
}

unsigned char	gradient_blue(t_fdf *fdf, t_vector *cur)
{
	char			style;
	unsigned char	blue;
	float			coef;

	style = fdf->view->style;
	coef = (float)(cur->z - fdf->min_h) / (fdf->max_h - fdf->min_h);
	if (style == 3 || style == 4 || style == 6)
		blue = 0xFF;
	else if (style == 1 || style == 2 || style == 5)
		blue = (int)(0xFF * coef);
	return (blue);
}
