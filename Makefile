CC = gcc
CFLAGS = -Wall -std=c17
OUT = pwdgen
SRC = src/*.c

all:
	@make build
	@make run

build:
	@$(CC) $(CFLAGS) $(SRC) -o out/$(OUT)

run:
	@./out/$(OUT)