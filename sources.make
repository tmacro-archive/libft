# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.make                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/05 10:34:05 by tmckinno          #+#    #+#              #
#    Updated: 2017/06/05 21:35:08 by tmckinno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC +=	ft_memalloc.c \
	ft_memdel.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_strnew.c \
	ft_strlen.c \
	ft_strdel.c \
	ft_memccpy.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c 
OBJ = $(SRC:.c=.o)
