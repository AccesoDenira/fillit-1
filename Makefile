# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashulha <ashulha@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/09 12:46:14 by ashulha           #+#    #+#              #
#    Updated: 2017/03/09 12:46:15 by ashulha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LNAM = libft.a

LIBF = ./includes/libft

INCL = ./src/fillit.h

SRCS = ./src

CCFL = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C $(LIBF) re
	@$(CCFL) -L $(LIBF) -lft $(SRCS)/*.c -I $(LIBF) -I $(INCL) -o $(NAME)

clean:
	@make -C $(LIBF) clean

fclean: clean
	@make -C $(LIBF) fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

