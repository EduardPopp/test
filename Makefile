##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## .
##

SRC	=	crashtesttest_e.c	\
	nb_to_str.c	\
	brackets_1.c	\
	brackets_2.c	\
	my_strtol.c

NAME	=	a.out

INC	=	-I include/

LMY	=	-L lib/my/ -lmy

all:	$(NAME) clean

$(NAME):
	gcc $(SRC) -o $(NAME) $(LMY) $(INC) -g3

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all