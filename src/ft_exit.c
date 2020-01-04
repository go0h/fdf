/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:39:28 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/04 12:29:30 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_exit(t_fdf **fdf, int err)
{
	free_fdf(fdf);
	if (err == USAGE)
		ft_fprintf(2, "USAGE: ./fdf [valid_map]\n");
	else if (err == MALLOC_FAILURE)
		ft_fprintf(2, "Error: malloc failure\n");
	else if (err == LINE_LENGTHS)
		ft_fprintf(2, "Error: different line lengths\n");
	else if (err == INVALID_COLOR)
		ft_fprintf(2, "Error: invalid color\n");
	else
		perror("Error: ");
	exit(err);
}
