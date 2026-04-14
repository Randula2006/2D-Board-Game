#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "terminal.h"
#include "player.h"
#include "random.h"
#include "enemy.h"
#include "game.h"

int main(int argc, char *argv[])
{
    Map *map;
    char input;
    int gameOver;
    int condition; /* 0 if the move is valid and 1 if it is wrong*/

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
            condition = movePlayer(map, input);
            gameOver = gameloop(map);

            if(gameOver == 0){
                controlEnemyMovement(map, condition);
                gameOver = gameloop(map);
            }
            
        }
        else if (input == 'u'){ /* player undo control */
            /*TODO: undo controls*/
        }
    }

    enableBuffer();

    printMap(map);  /* show final map state */
    
    if(gameOver == 1){
        printf("Congratulations: You Won!!!.\n");
    }
    if(gameOver == 2){
        printf("Player lose. Try again.\n");
    }

    /* release Malloc use of Map */
    freeMap(map);
    return 0;
}