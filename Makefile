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
CFLAGS = -msse3 -O3 -fomit-frame-pointer -funroll-loops -lm -I .

all: main$(EXT)
	$(CC) $(CFLAGS) -o main$(EXT) main.o qtsort.o

main$(EXT):
	$(CC) $(CFLAGS) -c main.c qtsort.c

clean:
	$(RM) main.o main$(EXT)
