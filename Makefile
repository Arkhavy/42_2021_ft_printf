# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 16:29:31 by ljohnson          #+#    #+#              #
#    Updated: 2021/12/04 11:18:14 by ljohnson         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libarkprintf.a
SRCS = ark_printf.c ark_int_putchar.c ark_int_putstr.c ark_int_putnbr.c \
	ark_int_strlen.c ark_int_putnbr_base.c ark_int_putptr.c
OBJS = ${SRCS:.c=.o}
HEAD = ark_printf.h
CC = gcc
CF = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

all: ${NAME}

%.o: %.c ${HEAD}
	${CC} ${CF} -c -o $@ $<

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re