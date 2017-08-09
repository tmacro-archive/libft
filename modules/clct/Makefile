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

include module.mak

ECHO	= @echo
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
OBJDIR	= build
INCLUDE	= -I ./

OBJ		= $(SRC:%.c=$(OBJDIR)/%.o)

.PHONY	= all clean fclean re deps

all: $(NAME)

$(NAME): $(OBJ)
	$(ECHO) :: :: Building archive $(NAME)
	@ar rcs $(NAME) $(OBJ)

$(OBJ):  | build

build:
	@mkdir -p $@

$(OBJDIR)/%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
