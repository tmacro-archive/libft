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
CFLAGS	= -Wall -Werror -Wextra
SRCDIR	= srcs
OBJDIR	= build
OUTPUT	= ../libs
INCLUDE	= -I includes

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
	@mkdir -p $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	rm -f $(OUTPUT)/$(NAME)

re: fclean all
