CFLAGS=-Wall -Wextra -Werror -pedantic
CC=clang $(CFLAGS)

all: math

math: math.c
	$(CC) $(CFLAGS) math.c -o math

clean:
	rm -f *.o math

infer:
	infer run -- make