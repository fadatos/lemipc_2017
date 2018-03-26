##
## EPITECH PROJECT, 2018
## malloc
## File description:
## lemipc
##

CC		= gcc
CFLAGS	+= -Wall -Wextra -Werror -W
LDFLAGS	= -lm

NAME	= lemipc

SRC		= srcs/main.c \
		srcs/utils.c \
	  	srcs/print_map.c \
	  	srcs/alone.c \
	  	srcs/drop_team.c \
	  	srcs/move.c \
	  	srcs/init.c

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	 $(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
