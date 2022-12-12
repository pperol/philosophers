# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pperol <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 12:55:22 by pperol            #+#    #+#              #
#    Updated: 2022/12/12 16:30:14 by pperol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC  = utils.c \
		philo.c

CC = clang

INC = philo.h

CFLAGS = Wall -Werror -Wextra -g3 -lpthread #-fsanitize=thread

OBJ = $(SRC:.c=.o)

# COLORS
CYAN		= 	\033[0;36m
PURPLE		= 	\033[0;35m
BLUE		= 	\033[0;34m
GREEN		= 	\033[0;32m
RESET		= 	\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
