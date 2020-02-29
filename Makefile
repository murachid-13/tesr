# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: murachid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/29 21:38:34 by murachid          #+#    #+#              #
#    Updated: 2020/02/24 17:41:53 by murachid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = *.c 
OBJS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = gcc

HEADER = ft_printf.h

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
 
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all 
