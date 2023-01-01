CFLAGS = -Wall -Werror -Wconversion -pedantic -std=c11
INC = -I ./include
OBJS = ./build/vector.o

all: sandbox.c
	cc -o debug sandbox.c $(CFLAGS)

vector: src/vector.c
	cc ./src/vector.c $(INC) $(CFLAGS) -c -o ./build/vector.o

# RUN CODE SANDBOX
.PHONY: run
run: all
	./debug

clean:
	rm -rf ./debug ./build/*
