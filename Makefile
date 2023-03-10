CFLAGS = -Wall -Werror -Wconversion -pedantic -std=c11
INC = -I ./include
OBJS = ./build/vector.o

# -fsanitize=leak
all: vector
	cc -o debug sandbox.c $(CFLAGS) $(INC) $(OBJS)

# -fsanitize=address
vector: src/vector.c
	cc ./src/vector.c $(INC) $(CFLAGS) -c -o ./build/vector.o

# RUN CODE SANDBOX
.PHONY: run
run: all
	./debug

clean:
	rm -rf ./debug ./build/*
