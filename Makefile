# **************************************************************************** #ME
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/05 09:30:29 by tmckinno          #+#    #+#              #
#    Updated: 2017/06/05 21:49:51 by tmckinno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -c
.PHONY = all clean fclean re

include sources.make

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC)
	ar -cvq $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean $(NAME)

all: $(NAME) 
