# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/15 00:05:28 by jvoor             #+#    #+#              #
#    Updated: 2019/10/16 12:04:21 by jvoor            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIB = ./libft/
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
	fdf_iso.c \
	ft_atoi_ox.c \
	is_valid.c \
	key_functions.c \
	key_functions_01.c

OBJ =   $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
FRAMEW = -lmlx -framework OpenGl -framework AppKit

.PHONY: all dir clean fclean re

all: $(NAME) 

%.o			: %.c
	$(CC) $(CFLAGS) -o $@  -c $<


$(NAME): $(OBJ)
	make -C $(LIB) re
	$(CC) $(CFLAGS) -L$(LIB) -lft -L.$(MLX) $(FRAMEW) $(OBJ) -o $(NAME)

clean:
	make -C $(LIB) fclean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
