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

ECHO	= @echo
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g -fsanitize=address
SRCDIR	= srcs
OBJDIR	= build
OUTPUT	= ../libs
INCLUDE	= -I includes -I ../str/includes -I ../clct/includes
LIBS	= -L ../libs -lstr

include module.mak

OBJ		= $(SRC:%.c=$(OBJDIR)/%.o)

.PHONY	= all clean fclean re deps

all: $(OUTPUT)/$(NAME)

$(OUTPUT)/$(NAME): | $(OUTPUT) $(OBJ)
	$(ECHO) :: :: Building archive $(OUTPUT)/$(NAME)
	@ar rcs $(OUTPUT)/$(NAME) $(OBJ)

$(OBJ):  | build

build:
	@mkdir -p $@

$(OUTPUT):
ifeq (0, $(shell [[ -L ./$(OUTPUT) ]] && echo 1 || echo 0))
	@mkdir -p $@
endif

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
ifeq (0, $(shell [[ -L ./$(OUTPUT) ]] && echo 1 || echo 0))
	rm -rf $(OUTPUT)
else
	rm -f $(OUTPUT)/$(NAME)
endif

re: fclean all
