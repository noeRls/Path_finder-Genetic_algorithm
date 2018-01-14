##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## generic
##

NAME	=	path_finder

INCLUDE	=	-I./include/

LIB	=	-L./lib/my/ -lmy -L./lib/my_csfml/ -lmycsfml -lc_graph_prog -lm

SRC	=	./srcs/main.c	\
		./srcs/graphic/even_handle.c	\
		./srcs/graphic/graphic_creation.c	\
		./srcs/graphic/run.c	\
		./srcs/graphic/update_map.c	\
		./srcs/graphic/update_species.c	\
		./srcs/graphic/render.c	\
		./srcs/genetic/initialisation.c	\
		./srcs/genetic/calcs.c \
		./srcs/genetic/reprod.c \

OBJ	=	$(SRC:.c=.o)

CPPFLAGS	=	$(INCLUDE) -g3

FLAG	=	-Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	make -C./lib/my/
	make -C./lib/my_csfml/
	gcc $(OBJ) -o $(NAME) $(CPPFLAGS) $(LIB) $(FLAG)

clean:
	make clean -C./lib/my_csfml/
	make clean -C./lib/my/
	rm -f $(OBJ)

fclean:	clean
	make fclean -C./lib/my_csfml/
	make fclean -C./lib/my/
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean all clean
