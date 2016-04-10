ifdef SystemRoot
	RM = del /Q
	EXT = .exe
else
	ifeq ($(shell uname), Linux)
		RM = rm -f
		EXT = 
	endif
endif

CC = gcc
CFLAGS = -Wall -g -msse3 -O3 -fomit-frame-pointer -funroll-loops -lm -I .

all: main$(EXT)
	$(CC) $(CFLAGS) -o main$(EXT) main.o qdsort.o

main$(EXT):
	$(CC) $(CFLAGS) -c main.c qdsort.c

clean:
	$(RM) main.o main$(EXT)
