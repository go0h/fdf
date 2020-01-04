/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:04:24 by pcredibl          #+#    #+#             */
/*   Updated: 2020/01/04 12:44:50 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTONS_H
# define BUTTONS_H

#ifdef __APPLE__
	# define MOUSE_LEFT_KEY		1
	# define MOUSE_RIGHT_KEY	2
	# define MOUSE_THIRD_KEY	3
	# define MOUSE_SCROLL_UP	4
	# define MOUSE_SCROLL_DOWN	5
	# define MOUSE_SCROLL_LEFT	6
	# define MOUSE_SCROLL_RIGHT	7

	# define ARROW_UP			126
	# define ARROW_DOWN			125
	# define ARROW_LEFT			123
	# define ARROW_RIGHT		124

	# define NUM_PAD_0			82
	# define NUM_PAD_1			83
	# define NUM_PAD_2			84
	# define NUM_PAD_3			85
	# define NUM_PAD_4			86
	# define NUM_PAD_5			87
	# define NUM_PAD_6			88
	# define NUM_PAD_7			89
	# define NUM_PAD_8			91
	# define NUM_PAD_9			92
	# define NUM_PAD_PLUS		69
	# define NUM_PAD_MINUS		78
	# define NUM_PAD_DIV		75
	# define NUM_PAD_EQUAL		81

	# define MAIN_PAD_ESC		53
	# define MAIN_PAD_I			34
	# define MAIN_PAD_P			35
	# define MAIN_PAD_0			29
	# define MAIN_PAD_1			18
	# define MAIN_PAD_2			19
	# define MAIN_PAD_3			20
	# define MAIN_PAD_4			21
	# define MAIN_PAD_5			23
	# define MAIN_PAD_6			22
	# define MAIN_PAD_7			26
	# define MAIN_PAD_8			28
	# define MAIN_PAD_9			25
	# define MAIN_PAD_PLUS		24
	# define MAIN_PAD_MINUS		27
	# define MAIN_PAD_LESS		43
	# define MAIN_PAD_MORE		47
	# define MAIN_PAD_A			0
	# define MAIN_PAD_S			1
	# define MAIN_PAD_D 		2
	# define MAIN_PAD_F 		3
	# define MAIN_PAD_G 		5
	# define MAIN_PAD_H 		4
	# define MAIN_PAD_C 		8
	# define MAIN_PAD_O 		31
	# define MAIN_PAD_P 		35
#else
	# define MAIN_PAD_A			97
	# define MAIN_PAD_S			115
	# define MAIN_PAD_D			100
	# define MAIN_PAD_F			102
	# define MAIN_PAD_G			103
	# define MAIN_PAD_H			104
	# define MAIN_PAD_I			105
	# define MAIN_PAD_O			111
	# define MAIN_PAD_P			112
	# define MAIN_PAD_C			110
	# define ARROW_UP			65362
	# define ARROW_DOWN			65364
	# define ARROW_LEFT			65361
	# define ARROW_RIGHT		65363
	# define MAIN_PAD_ESC		65307
	# define MAIN_PAD_PLUS		61
	# define MAIN_PAD_MINUS		45
	# define NUM_PAD_1			65436
	# define NUM_PAD_2			65433
	# define NUM_PAD_3			65435
	# define NUM_PAD_4			65430
	# define NUM_PAD_5			65437
	# define NUM_PAD_6			65432
	# define NUM_PAD_7			65429
	# define NUM_PAD_8			65431
	# define NUM_PAD_9			65434
	# define NUM_PAD_0			65438
	# define NUM_PAD_DIV		65455
	# define NUM_PAD_PLUS		65451
	# define NUM_PAD_MINUS		65453
	# define NUM_PAD_EQUAL		81

	# define MOUSE_LEFT_KEY		1
	# define MOUSE_RIGHT_KEY	2
	# define MOUSE_THIRD_KEY	3
	# define MOUSE_SCROLL_UP	4
	# define MOUSE_SCROLL_DOWN	5
	# define MOUSE_SCROLL_LEFT	6
	# define MOUSE_SCROLL_RIGHT	7
#endif
#endif
