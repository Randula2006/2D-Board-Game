#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "map.h"
#include "terminal.h"
#include "player.h"
#include "enemy.h"

int gameloop(Map *map){
    int result;

    /* Winning Scenario */
    if (map->treasureCollected && ((map->playerRow == map->goalRow) && (map->playerCol == map->goalCol)))
    {
        result = 1;
    }
    /* Losing Scenario */
    else if ((map->playerRow == map->enemyRow) && (map->playerCol == map->enemyCol))
    {
        result = 2;
    }
    else
    {
        /* Normal play */
        result = 0;
    }

    return result;
}

