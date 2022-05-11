#compiler
CC = gcc

#flags
CFLAGS = -Wall -Wextra -Werror -Wno-comment -Wno-error=comment

test: 1dca.o 1dca_tester.o
	$(CC) $(CFLAGS) 1dca.o 1dca_tester.o -o test.out

ca.o: 1dca.c 1dca.h
	$(CC) $(CFLAGS) -c 1dca.c

ca_tester.o: 1dca_tester.c
	$(CC) $(CFLAGS) -c 1dca_tester.c
clean:
	-@rm *.o *.out 2>/dev/null || true

