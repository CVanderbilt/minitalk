SERVER=server

CLIENT=client

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

LDFLAGS=-L.

LDLIBS=-lft

BMP=srcs/bmp.c

SSRC=server.c utils.c

CSRC=client.c utils.c

SOBJ=$(SSRC:.c=.o)

COBJ=$(CSRC:.c=.o)


$(SERVER):
	$(CC) $(CFLAGS) -c $(SSRC)
	$(CC) $(CFLAGS) -c client.c
	$(CC) $(CFLAGS) -o $(SERVER) $(SOBJ)
	$(CC) $(CFLAGS) -o $(CLIENT) $(COBJ) 

all: $(SERVER)

clean:
	$(RM) $(COBJ) $(SOBJ)

fclean: clean
	$(RM) -rf $(SERVER) $(SERVER).dSYM
	$(RM) -rf $(CLIENT) $(CLIENT).dSYM

re: fclean all

.PHONY: clean fclean all bonus