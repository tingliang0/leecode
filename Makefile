.PHONY: all clean

SRC=$(wildcard *.c)
BIN=$(SRC:%.c=%)
CC=gcc
CFLAGS=-Wall -std=c99

all: $(BIN)

clean:
	rm -rf $(BIN)
