# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pperol <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 12:55:22 by pperol            #+#    #+#              #
#    Updated: 2023/01/31 12:39:18 by pperol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = 	utils.c \
		philosophers_state.c \
		meal_state.c \
		parsing_and_init.c \
		philosophers_end.c \
		philo.c 

CC = clang

INC = philo.h

#CFLAGS = -Wall -Werror -Wextra -g3

LFLAGS = -lpthread

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LFLAGS) -o $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
