CC := gcc
FLAGS := -std=c99 -Wall -Werror -Wextra

build:
	$(CC) $(FLAGS) main.c -c 
	$(CC) $(FLAGS) shapes.c -c 
	$(CC) $(FLAGS) cli.c -c
	$(CC) $(FLAGS) main.o shapes.o cli.o -o main

clean:
	rm bin/*