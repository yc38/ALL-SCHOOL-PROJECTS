# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychirouz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 13:32:34 by ychirouz          #+#    #+#              #
#    Updated: 2023/06/28 13:01:19 by ychirouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = actions.c init.c main.c parsing.c utils.c 

OBJ = ${SRC:.c=.o}

CC = gcc -Wall -Wextra -Werror -g -pthread

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
