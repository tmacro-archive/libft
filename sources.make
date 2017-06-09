# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.make                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/05 10:34:05 by tmckinno          #+#    #+#              #
#    Updated: 2017/06/08 19:58:08 by tmckinno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC +=	ft_memalloc.c \
	ft_memdel.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnew.c \
	ft_strlen.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strcpy.c \
	ft_strdup.c \
	ft_strncpy.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strncat.c \
	ft_strrchr.c \
	ft_strcmp.c \
	ft_strstr.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_tolower.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_isws.c \
	ft_strtrim.c \
	ft_strsplit.c \
	ft_ctrim.c

OBJ = $(SRC:.c=.o)
