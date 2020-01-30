CC = gcc

CFLAGS =  -c
CLIB =  -ljson



final:main.c
	$(CC) main.c $(CLIB)$(CFLAGS) -o main

clean:
	rm main