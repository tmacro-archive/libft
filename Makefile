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

.PHONY = all clean fclean re headers

all: $(NAME) 

$(NAME): modules/libmcro.a headers
	@cp ./modules/libmcro.a ./libft.a

headers:
	@cp modules/*/includes/* includes/

modules/libmcro.a:
	@make -C modules

clean:
	@make -C modules clean

fclean:
	@rm -f $(NAME)
	@make -C modules fclean

re: fclean $(NAME)

