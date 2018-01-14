##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## libmy
##

SRC	=	framebuffer.c	\
		window_tool.c	\
		eazy_stuff.c	\
		pong_tool.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmycsfml.a

LIB	=	-lc_graph_prog

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean all
