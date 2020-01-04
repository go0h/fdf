/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:43:41 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/12 12:22:35 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_rotate_info(void *mlx_ptr, void *win_ptr, void *img_ptr)
{
	mlx_string_put(mlx_ptr, win_ptr, 5, 0, RED, "ROTATE:");
	mlx_string_put(mlx_ptr, win_ptr, 5, 20, YELLOW, "on X: ");
	mlx_string_put(mlx_ptr, win_ptr, 65, 20, WHITE, "Key '2' / '8'");
	mlx_string_put(mlx_ptr, win_ptr, 65, 40, WHITE, "or click by mouse on \
	upper middle");
	mlx_string_put(mlx_ptr, win_ptr, 65, 60, WHITE, "or bottom middle side of \
	screen");
	mlx_string_put(mlx_ptr, win_ptr, 5, 80, YELLOW, "on Y: ");
	mlx_string_put(mlx_ptr, win_ptr, 65, 80, WHITE, "Key '4' / '6'");
	mlx_string_put(mlx_ptr, win_ptr, 65, 100, WHITE, "or click by mouse on \
	left middle");
	mlx_string_put(mlx_ptr, win_ptr, 65, 120, WHITE, "or right middle side \
	of screen");
	mlx_string_put(mlx_ptr, win_ptr, 5, 140, YELLOW, "on Z:");
	mlx_string_put(mlx_ptr, win_ptr, 65, 140, WHITE, "Key '1' / '3' / '7' / \
	'9'");
	mlx_string_put(mlx_ptr, win_ptr, 65, 160, WHITE, "or click by mouse \
	on corners");
	mlx_string_put(mlx_ptr, win_ptr, 65, 180, WHITE, "of the screen");
}

static void	put_shift_info(void *mlx_ptr, void *win_ptr, void *img_ptr)
{
	mlx_string_put(mlx_ptr, win_ptr, 5, 220, RED, "SHIFT:");
	mlx_string_put(mlx_ptr, win_ptr, 5, 240, YELLOW, "on X:");
	mlx_string_put(mlx_ptr, win_ptr, 65, 240, WHITE, "Use LEFT & RIGHT arrows");
	mlx_string_put(mlx_ptr, win_ptr, 5, 260, YELLOW, "on Y:");
	mlx_string_put(mlx_ptr, win_ptr, 65, 260, WHITE, "Use UP & DOWN arrows");
}

static void	put_zoom_relief_info(void *mlx_ptr, void *win_ptr, void *img_ptr)
{
	mlx_string_put(mlx_ptr, win_ptr, 5, 300, RED, "ZOOM:");
	mlx_string_put(mlx_ptr, win_ptr, 5, 320, YELLOW, "Increase:");
	mlx_string_put(mlx_ptr, win_ptr, 105, 320, WHITE, "Key '+' \
	on main keyboard");
	mlx_string_put(mlx_ptr, win_ptr, 105, 340, WHITE, "or scroll \
	down by mouse");
	mlx_string_put(mlx_ptr, win_ptr, 5, 360, YELLOW, "Reduce:");
	mlx_string_put(mlx_ptr, win_ptr, 105, 360, WHITE, "Key '-' on \
	main keyboard");
	mlx_string_put(mlx_ptr, win_ptr, 105, 380, WHITE, "or scroll up by mouse");
	mlx_string_put(mlx_ptr, win_ptr, 5, 400, RED, "RELIEF:");
	mlx_string_put(mlx_ptr, win_ptr, 5, 420, YELLOW, "Increase:");
	mlx_string_put(mlx_ptr, win_ptr, 105, 420, WHITE, "Key '+' on \
	num keyboard");
	mlx_string_put(mlx_ptr, win_ptr, 5, 440, YELLOW, "Reduce:");
	mlx_string_put(mlx_ptr, win_ptr, 105, 440, WHITE, "Key '-' on \
	num keyboard");
}

static void	put_view_info(void *mlx_ptr, void *win_ptr, void *img_ptr)
{
	mlx_string_put(mlx_ptr, win_ptr, 5, 480, RED, "VIEWS:");
	mlx_string_put(mlx_ptr, win_ptr, 5, 500, YELLOW, "Isometric:");
	mlx_string_put(mlx_ptr, win_ptr, 200, 500, WHITE, "Key 'I' or '/'");
	mlx_string_put(mlx_ptr, win_ptr, 5, 520, YELLOW, "In profile:");
	mlx_string_put(mlx_ptr, win_ptr, 200, 520, WHITE, "Key 'P' or '='");
	mlx_string_put(mlx_ptr, win_ptr, 5, 540, YELLOW, "view from the top:");
	mlx_string_put(mlx_ptr, win_ptr, 200, 540, WHITE, "Key 'O' or '0'");
	mlx_string_put(mlx_ptr, win_ptr, 5, 580, RED, "CHANGE COLORS:");
	mlx_string_put(mlx_ptr, win_ptr, 5, 600, WHITE, "Press 'C'");
}

void		put_legend(void *mlx_ptr, void *win_ptr, void *img_ptr)
{
	put_rotate_info(mlx_ptr, win_ptr, img_ptr);
	put_shift_info(mlx_ptr, win_ptr, img_ptr);
	put_zoom_relief_info(mlx_ptr, win_ptr, img_ptr);
	put_view_info(mlx_ptr, win_ptr, img_ptr);
	mlx_string_put(mlx_ptr, win_ptr, 5, 640, RED, "Exit:");
	mlx_string_put(mlx_ptr, win_ptr, 5, 680, WHITE, "Press 'Esc' ");
	mlx_string_put(mlx_ptr, win_ptr, 120, 680, WHITE, "or click 'X' on window");
}
