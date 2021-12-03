SRC = libft/ft_putnbr.c\
	libft/ft_putstr.c\
	libft/ft_putchar.c\

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
