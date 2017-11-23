# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/23 11:38:53 by tmckinno          #+#    #+#              #
#    Updated: 2017/10/14 13:53:33 by tmckinno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libmcro.a

ECHO	=	@echo
CC		= 	gcc
CFLAGS	= 	-Wall -Werror -Wextra -g
INCLUDE	= 	-I includes
MODULES	=	clct \
			mem \
			io \
			str \
			util \
			dict 
			# logr

LIBDIR	=	libs
LIBS	=	$(addprefix $(LIBDIR)/lib, $(MODULES:%=%.a)) 
OBJ		= 	$(SRC:%.c=$(OBJDIR)/%.o)
SRCS	=	
.PHONY	= all clean fclean re deps
.PHONY := $(MODULES)


all: $(NAME)

$(NAME): $(LIBS)
	$(ECHO) ":: :: Bundling archives into libmcro.a"
	@libtool -static -o $(NAME) $(LIBS)

$(OBJ):  | build

build:
	@mkdir -p $@

mri:
	@echo create $(NAME) > $(NAME).mri

$(LIBDIR)/lib%.a: ./% 
	@make -C $<

clean:
	@for mod in $(MODULES); do \
		make -sC $$mod clean ; \
	done

fclean:
	@rm -f $(NAME)
	@for mod in $(MODULES); do \
		make -sC $$mod fclean ; \
	done

re: fclean all
