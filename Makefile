# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 15:47:32 by pcredibl          #+#    #+#              #
#    Updated: 2020/01/04 12:42:09 by astripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= fdf

OBJ_DIR			:= ./obj
INC_DIR			:= ./inc
LIB_DIR			:= ./libft
SRC_DIR			:= ./src

CC				:= gcc
CFLAGS			:= -Wall -Wextra -Werror
LFLAGS			:= -I $(INC_DIR) -I /usr/local/include/ -I $(LIB_DIR)/inc
LIBS			= -L $(LIB_DIR) -lft

HEADERS			:= fdf.h buttons.h color.h

LIBFT			:= libft.a
LIBMLX			:= libmlx.a

UNAME 			:= $(shell uname -s)

ifeq ($(UNAME), Linux)
	LIBS		+= -lmlx -lXext -lX11 -lm
	MLX_DIR 	+=./minilibx/Ubuntu
else
	LIBS		+= -L ./minilibx/MacOS -lmlx -framework OpenGL -framework AppKit -lm
	MLX_DIR 	+=./minilibx/MacOS
endif

SRC 			= fdf.c ft_exit.c fdf_create.c vector_create.c\
				coordinates_and_color.c initialize.c bresenham.c\
				draw.c hooks.c matrix_create.c matrix_actions.c\
				legend.c gradient_color.c mix_color.c zbuffer.c

OBJ				= $(SRC:.c=.o)

vpath %.h $(INC_DIR)
vpath %.c $(SRC_DIR)
vpath %.o $(OBJ_DIR)
vpath %.a $(LIB_DIR) $(MLX_DIR) 

all: $(NAME)

$(NAME): libs $(OBJ) $(HEADERS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(LFLAGS) $(addprefix $(OBJ_DIR)/, $(OBJ)) $(LIBS) -o $@

$(OBJ):%.o:%.c $(LIBFT) $(LIBMLX) $(HEADERS) | $(OBJ_DIR)
	$(CC) $(LFLAGS) -o $(OBJ_DIR)/$@ -c $<

libs:
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(MAKE) $@ -C $(LIB_DIR)
	$(MAKE) $@ -C $(MLX_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) $@ -C $(LIB_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re libs

.SILENT: all $(NAME) $(OBJ) $(OBJ_DIR) clean fclean re libs
