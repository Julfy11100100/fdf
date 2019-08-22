# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvoor <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/15 00:05:28 by jvoor             #+#    #+#              #
#    Updated: 2019/08/15 00:05:31 by jvoor            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

GNL_DIR = ./get_next_line/
LIB = ./get_next_line/libft/
MLX_DIR = ./mlx/

HEADER = fdf.h 

SRC = fdf.c \
	fdf_clean_functions.c \
	fdf_clean_functions_01.c \
	fdf_color_functions.c \
	fdf_print_functions.c \
	fdf_print_line.c \
	fdf_read_functions.c \
	fdf_table_functions.c \
	fdf_wind.c \
	ft_atoi_ox.c \
	is_valid.c \
	key_functions.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
GNL = $(GNL_DIR)/get_next_line.c
FRAMEW = -lmlx -framework OpenGl -framework AppKit

.PHONY: all dir clean fclen re

all: $(NAME) 

$(NAME): $(SRC)
	make -C $(LIB) re
	$(CC) $(CFLAGS) $(GNL) -L$(LIB) -lft -L.$(MLX) $(FRAMEW) $(SRC) -o $(NAME)

clean:
	make -C $(LIB) fclean

fclean: clean
	rm -rf $(NAME)

re: fclean all
