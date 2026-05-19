CC = gcc
CFLAGS = -Wall -ansi -pedantic

OBJ = main.o map.o player.o enemy.o terminal.o linked_list.o game.o random.o

labyrinth: $(OBJ)
	$(CC) $(OBJ) -o labyrinth

main.o: main.c map.h terminal.h player.h random.h enemy.h game.h linked_list.h
	$(CC) $(CFLAGS) -c main.c

map.o: map.c map.h
	$(CC) $(CFLAGS) -c map.c

player.o: player.c player.h map.h
	$(CC) $(CFLAGS) -c player.c

enemy.o: enemy.c enemy.h map.h
	$(CC) $(CFLAGS) -c enemy.c

terminal.o: terminal.c terminal.h
	$(CC) $(CFLAGS) -c terminal.c

linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c linked_list.c

game.o: game.c game.h map.h
	$(CC) $(CFLAGS) -c game.c

random.o: random.c random.h
	$(CC) $(CFLAGS) -c random.c

clean:
	rm -f $(OBJ) labyrinth