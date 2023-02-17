# Compiling the program with flags
NAME = libgnl.a

.SUFFIXES: .o .c

# Macros
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = get_*.c
OBJ = $(SRC:.c=.o)
REMOVE = rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	 ar -rcs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)


clean:
	${REMOVE} ${OBJ}

fclean: clean
	${REMOVE} $(NAME)

re: fclean all

.PHONY: all clean fclean re