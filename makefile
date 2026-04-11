CC = gcc
CFLAGS = -Wall -ansi -pedantic

OBJ = main.o map.o

labyrinth: $(OBJ)
	$(CC) $(OBJ) -o labyrinth

main.o: main.c map.h
	$(CC) $(CFLAGS) -c main.c

map.o: map.c map.h
	$(CC) $(CFLAGS) -c map.c

clean:
	rm -f $(OBJ) labyrinth