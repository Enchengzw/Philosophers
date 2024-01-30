# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 16:53:06 by ezhou             #+#    #+#              #
#    Updated: 2024/01/29 16:49:51 by ezhou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

USER = ezhou

RM = rm -f
INCLUDE = Include/

CC = gcc 
CFLAGS = -g -Wall -Wextra -Werror

NAME = philo
SRC = parse.c not_libft.c philo.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -I./$(INCLUDE) -o $(NAME) $(OBJ) 
	@echo "$(COLOUR_GREEN)(•̀ᴗ•́)و $(NAME) generado!$(COLOUR_END)"

%.o : %.c
	@$(CC) -I./$(INCLUDE) -c -o $@ $<
	@echo "$(COLOUR_BLUE)(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compilando archivos .c$(COLOUR_END)" 

clean:
	@$(RM) $(OBJ)
	@echo "$(COLOUR_RED)¯\_(ツ)_/¯ Objectos removidos!$(COLOUR_RED)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(COLOUR_RED)(╯°□°）╯︵ ┻━┻ $(NAME) removido!$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re 