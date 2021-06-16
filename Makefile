SERVER=server

BSERVER=server_bonus

CLIENT=client

BCLIENT=client_bonus

UTILS=utils

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

LDFLAGS=-L.

LDLIBS=-lft

BMP=srcs/bmp.c

SSRC=utils1.c utils2.c send_msg.c

OBJ=$(SSRC:.c=.o)
 
all: $(SERVER) $(CLIENT)

bonus: $(BSERVER) $(BCLIENT)

$(SERVER):
	$(CC) $(CFLAGS) -c $(SSRC)
	$(CC) $(CFLAGS) -c server.c
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJ) server.o

$(CLIENT):
	$(CC) $(CFLAGS) -c $(SSRC)
	$(CC) $(CFLAGS) -c client.c
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ) client.o

$(BSERVER):
	$(CC) $(CFLAGS) -c $(SSRC)
	$(CC) $(CFLAGS) -c server_bonus.c
	$(CC) $(CFLAGS) -o $(SERVER)_bonus $(OBJ) server_bonus.o

$(BCLIENT):
	$(CC) $(CFLAGS) -c $(SSRC)
	$(CC) $(CFLAGS) -c client_bonus.c
	$(CC) $(CFLAGS) -o $(CLIENT)_bonus $(OBJ) client_bonus.o

clean:
	$(RM) $(OBJ) server.o client.o
	$(RM) server_bonus.o client_bonus.o

fclean: clean
	$(RM) -rf $(SERVER) $(SERVER).dSYM $(BSERVER) $(BSERVER).dSYM
	$(RM) -rf $(CLIENT) $(CLIENT).dSYM $(BCLIENT) $(BCLIENT).dSYM

re: fclean all

.PHONY: clean fclean all bonus