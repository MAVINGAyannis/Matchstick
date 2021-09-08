##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	./main.c	\
			./main.h	\
			./mapmaker.c	\
			./gameplay.c	\
			./error.c	\
			./error_move.c	\
			./other.c	\
			./other_2.c	\
			./optimisation.c	\
			./lib/my/my_printf.c	\
			./lib/my/my_putchar.c	\
			./lib/my/my_put_nbr.c	\
			./lib/my/my_putstr.c	\
			./lib/my/my_getnbr.c		\
			./lib/my/my_str_isnum.c	\
			./lib/my.h	\

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(SRC) -o $(NAME)

clean:
	rm *.o
	rm lib/my/*.o

fclean: clean
	rm $(NAME)

re:	all
	make clean
