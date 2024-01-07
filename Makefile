# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seng <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 00:12:21 by plaophit          #+#    #+#              #
#    Updated: 2024/01/07 04:40:38 by seng             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c

OBJ = ${SRC:.c=.o}

all:	$(NAME)

$(NAME):$(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: re clean fclean all
