# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 16:18:28 by latahbah          #+#    #+#              #
#    Updated: 2022/02/24 17:57:05 by latahbah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIST =	main.c				end.c 					render_frame.c \
		get_next_line.c		get_next_line_utils.c 	init.c \
		get_map.c			map_init.c				make_move.c \
		check_map.c			draw_map.c

LIB = libft_new/libft.a

OBJ = $(patsubst %.c,%.o,$(LIST))

D_FILES = $(patsubst %.c,%.d,$(LIST))

COLOR 		=  \033[0;32m
NO_COLOR 	=	\033[0m 

OPTFLAGS = -O2
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME)::
	@cd libft_new && make

$(NAME):: $(OBJ)
	@gcc $(FLAGS) $(OPTFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit $(LIB) -I. -o $(NAME)
	@echo "$(COLOR)SO_LONG - OK$(NO_COLOR)"
	

%.o : %.c
	@gcc $(FLAGS) $(OPTFLAGS) -Imlx -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean::
	@cd libft_new && make clean

clean::
	@rm -f $(OBJ) $(D_FILES)

fclean:: clean
	@cd libft_new && make fclean

fclean:: clean
	@rm -f $(NAME)

re:: fclean	all

.PHONY: all clean fclean re bonus
