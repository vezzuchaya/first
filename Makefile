# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkakuna <vkakuna@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/16 17:52:47 by vkakuna           #+#    #+#              #
#    Updated: 2021/12/23 15:03:49 by vkakuna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	ft_printf.c	\
		ft_printf_utils.c
		
OBJ = $(patsubst %.c,%.o,$(SRCS))

OPTFLAGS = -O2
FLAGS = -Wall -Wextra -Werror
RM = rm -f


all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $?

%.o: %.c ft_printf.h
	gcc $(FLAGS) $(OPTFLAGS) -c $< -o $(<:.c=.o)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)
		
re:		fclean all

.PHONY: all clean fclean re
