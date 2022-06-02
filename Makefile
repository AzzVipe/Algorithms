CC=gcc
HEADER=header
SRCPATH=src
CFLAGS=-Iheader
CFLAGS+=-g

main: main.c
	$(CC) -o main main.c $(CFLAGS)
