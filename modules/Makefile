# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/23 11:38:53 by tmckinno          #+#    #+#              #
#    Updated: 2017/08/06 23:01:33 by tmckinno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libmcro.a

ECHO	=	@echo
CC		= 	gcc
CFLAGS	= 	-Wall -Werror -Wextra -g
INCLUDE	= 	-I includes
LIBDIR	=	libs
MODULES	=	clct \
			mem \
			io
			# str \
			# util \
			# dict
LIBS	=	$(addprefix $(LIBDIR)/lib, $(MODULES:%=%.a)) 
SRCS	= 	$(addprefix $(LIBDIR)/, $(SRC))
OBJ		= 	$(SRC:%.c=$(OBJDIR)/%.o)

.PHONY	= all clean fclean re deps
.PHONY := $(MODULES)


all: $(NAME)

$(NAME): $(LIBS)
	$(ECHO) -e "save\nend" >> $(NAME).mri
	ar -M < $(NAME).mri

$(OBJ):  | build

build:
	@mkdir -p $@

mri:
	@echo create $(NAME) > $(NAME).mri

$(LIBDIR)/lib%.a: ./% | mri
ifeq (0, $(shell [[ -L ./$</libs ]] && echo 1 || echo 0))
	# ln -s ../libs ./$</libs
endif
	@make -C $<
	echo addlib $(LIBDIR)/lib$<.a >> $(NAME).mri

clean:
	@rm -f $(NAME).mri
	@for mod in $(MODULES); do \
		make -sC $$mod clean ; \
	done

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME).mri
	@for mod in $(MODULES); do \
		make -sC $$mod clean ; \
	done

re: fclean all
