#compiler
CC = gcc

#flags
CFLAGS = -Wall -Wextra -Werror -Wno-comment -Wno-error=comment

2dtest: 2dca.o 2dca_main.o
	$(CC) $(CFLAGS) 2dca.o 2dca_tester.o -o 2dtest.out
test: 1dca.o 1dca_tester.o
	$(CC) $(CFLAGS) 1dca.o 1dca_tester.o -o test.out

1dca.o: src/1dca.c src/1dca.h
	$(CC) $(CFLAGS) -c src/1dca.c

1dca_tester.o: src/1dca_tester.c
	$(CC) $(CFLAGS) -c src/1dca_tester.c

2dca.o: src/2dca.c src/2dca.h
	$(CC) $(CFLAGS) -c src/2dca.c

2dca_main.o: src/2dca_main.c
	$(CC) $(CFLAGS) -c src/2dca_main.c

clean:
	-@rm *.o *.out 2>/dev/null || true

