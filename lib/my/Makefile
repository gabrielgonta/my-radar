##
## EPITECH PROJECT, 2023
## my-radar
## File description:
## Libmy Makefile
##

CC 			= 	gcc

SRC			=	my_count_char.c    \
				my_int_to_strnum.c \
				my_intlen.c        \
				my_putchar.c       \
				my_puterr.c        \
				my_putstr.c        \
				my_revstr.c        \
				my_strcat.c        \
				my_strcmp.c        \
				my_strlen.c        \
				my_strtol.c        \
				my_strdupcat.c     \

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-W -Wall -Wextra -Werror

DBFLAGS		=	-g -g3 -ggdb

HEADER		=	my.h

NAME		=	libmy.a

all:		$(OBJ)
			ar rc $(NAME) $(OBJ)
			cp $(NAME) ../
			cp $(HEADER) ../../include

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)
			rm -f ../$(NAME)
			rm -f ../../include/$(HEADER)

re:			fclean all

.phony:		re fclean clean
