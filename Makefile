# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plaophit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 00:12:21 by plaophit          #+#    #+#              #
#    Updated: 2024/01/07 00:12:27 by plaophit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
      ft_printf_c.c \
      ft_printf_s.c \
      ft_printf_p.c \
      ft_printf_di.c \
      ft_printf_u.c \
      ft_printf_x.c \
      ft_printf_bx.c \

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
