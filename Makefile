CC = gcc
CFLAGS = -Wall -std=c17
OUT = pwdgen
SRC = src/*.c

build:
	@$(CC) $(CFLAGS) $(SRC) -o out/$(OUT)

all:
	@make build
	@make run

run:
	@./out/$(OUT)