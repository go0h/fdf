/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 10:37:12 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/05 13:34:56 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		**create_matrix(void)
{
	float	**matrix;
	int		i;
	int		j;

	if (!(matrix = (float**)malloc(sizeof(float*) * 3)))
		return (NULL);
	i = 0;
	while (i < 3)
	{
		if (!(matrix[i] = (float*)malloc(sizeof(float*) * 3)))
		{
			free_matrix(&matrix);
			return (NULL);
		}
		j = 0;
		while (j < 3)
		{
			matrix[i][j] = 0.0;
			++j;
		}
		++i;
	}
	return (matrix);
}

float		**matrix_x(float alpha)
{
	float	**matrix;

	if (!(matrix = create_matrix()))
		return (NULL);
	matrix[0][0] = 1.0;
	matrix[1][1] = cos(alpha);
	matrix[1][2] = -sin(alpha);
	matrix[2][1] = -matrix[1][2];
	matrix[2][2] = matrix[1][1];
	return (matrix);
}

float		**matrix_y(float alpha)
{
	float	**matrix;

	if (!(matrix = create_matrix()))
		return (NULL);
	matrix[0][0] = cos(alpha);
	matrix[0][2] = sin(alpha);
	matrix[1][1] = 1.0;
	matrix[2][0] = -matrix[0][2];
	matrix[2][2] = matrix[0][0];
	return (matrix);
}

float		**matrix_z(float alpha)
{
	float	**matrix;

	if (!(matrix = create_matrix()))
		return (NULL);
	matrix[0][0] = cos(alpha);
	matrix[0][1] = -sin(alpha);
	matrix[1][0] = -matrix[0][1];
	matrix[1][1] = matrix[0][0];
	matrix[2][2] = 1.0;
	return (matrix);
}

float		**matrix_orto(void)
{
	float	**matrix;

	if (!(matrix = create_matrix()))
		return (NULL);
	matrix[0][0] = 1.0;
	matrix[1][1] = matrix[0][0];
	matrix[2][2] = matrix[0][0];
	return (matrix);
}
