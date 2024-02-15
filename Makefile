CC = gcc
CFLAGS = -Wall -std=c17
OUT = pwdgen
SRC = src/*.c
DESTDIR = /usr/local/bin

build:
	@$(CC) $(CFLAGS) $(SRC) -o out/$(OUT)

all:
	@make clean
	@make build
	@make run

run:
	@./out/$(OUT)

clean:
	@rm -rf out/$(OUT)

install:
	@cp -rf out/$(OUT) $(DESTDIR)
