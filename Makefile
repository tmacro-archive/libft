# **************************************************************************** #ME
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/05 09:30:29 by tmckinno          #+#    #+#              #
#    Updated: 2017/10/14 13:52:17 by tmckinno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all: $(NAME) 

$(NAME): modules/libmcro.a
	@cp ./modules/libmcro.a ./libft.a

modules/libmcro.a:
	@make -C modules

clean:
	@make -C modules clean

fclean:
	@make -C modules fclean
	@rm -f $(NAME)

re: fclean $(NAME)

