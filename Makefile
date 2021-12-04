SRC = ft_calloc.c tobase.c ft_toupper.c 

OBJ = ${SRC:.c=.o}

NAME = libftprintf.a

all: ${NAME}

${NAME}: ${OBJ}

.c.o:
	cc -Wall -Werror -Wextra -c $(SRC)
	ar -rc ${NAME} $(OBJ)

clean:
	rm -rf $(OBJ) 

fclean:
	rm -rf ${OBJ} ${NAME}

re: fclean all

.PHONY : re all fclean clean
