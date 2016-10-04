# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/05 09:39:50 by jpepin            #+#    #+#              #
#    Updated: 2016/09/20 09:12:52 by jpepin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I./
LDLIBS = -ltermcap -lft
LDFLAGS = -Llibft/

LIB = libslct.a
NAME = ft_select

SRC = main.c \
			command_line.c \
			coucou_init.c \
			do_exit.c \
			fleche.c \
			fleche_de_droite.c \
			fleche_de_gauche.c \
			fleche_du_bas.c \
			fleche_du_haut.c \
			free_coucou.c \
			free_mapper.c \
			free_matrix.c \
			ft_tri.c \
			ft_signal.c \
			get_coords.c \
			get_names.c \
			get_size.c \
			go_to.c \
			idle.c \
			init_slide.c \
			init_wind.c \
			matrix_init.c \
			mouse.c \
			put_result.c \
			remove_file.c \
			select_cure.c \
			select_error.c \
			select_ret.c \
			select_warning.c \
			slide.c \
			term_coord.c \
			term_init.c \
			wind_clear.c \
			wind_line.c \
			windower.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C ./libft
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(SRC) -c
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)

lib:
	@$(CC) $(CPPFLAGS) $(SRC) -c
	@ar rc $(LIB) $(OBJ)

clean:
	@make clean -C ./libft
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C ./libft
	@$(RM) $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re
