#compiler
CC = gcc

#flags
CFLAGS = -Wall -Wextra -Werror -Wno-comment -Wno-error=comment

test: 1dca.o 1dca_tester.o
	$(CC) $(CFLAGS) 1dca.o 1dca_tester.o -o test.out

1dca.o: src/1dca.c src/1dca.h
	$(CC) $(CFLAGS) -c src/1dca.c

1dca_tester.o: src/1dca_tester.c
	$(CC) $(CFLAGS) -c src/1dca_tester.c
clean:
	-@rm *.o *.out 2>/dev/null || true

