#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "terminal.h"
#include "player.h"
#include "random.h"

int main(int argc, char *argv[])
{
    Map *map;
    char input;
    int gameOver;

    /* Calling at the start of the program to set the seed*/
    initRandom();

    if (argc != 2)
    {
        printf("Usage: ./labyrinth <map_file>\n");
        return 1;
    }

    map = createMap(argv[1]);
    gameOver = 0;

    disableBuffer();
    system("clear"); /* clear once at the start */

    while(gameOver == 0){
        printMap(map);
        
        input = getInput();

        if (input == 'w' || input == 'a' || input == 's' || input == 'd'){
            /* TODO: make movement for the character*/
            movePlayer(map, input);
        }
        else if (input == 'u'){ /* player undo control */
            /*TODO: undo controls*/
        }
    }

    enableBuffer();
    freeMap(map);
    return 0;
}