NAME	=	fillit
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SRC		=	fillitmain.c handlefiles.c usefulfuncs.c solve.c\
			tetriminos.c placevar.c fileval.c
OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
