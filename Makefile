NAME = client
NAME1 = server
SRC = client.c
SRC1 = server.c
OBJ = $(SRC:.c=.o)
OBJ1 = $(SRC1:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror


all: $(NAME) $(NAME1)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  -o $(NAME) 

$(NAME1) : $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -o $(NAME1) 

clean:
		rm -f *.o

fclean: clean
		rm -f client server
re: fclean all