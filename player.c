#include <stdlib.h>
#include <stdio.h>
#include "player.h"
#include "map.h"

int movePlayer(Map *map, char input){

    int condition;

    if(input == 'w'){
        condition = moveUp(map);
    }else if(input == 'a'){
        condition = moveLeft(map);
    }else if(input == 's'){
        condition = moveDown(map);
    }else if(input == 'd'){
        condition = moveRight(map);
    }else{
        condition = 0;
    }


    return condition;
}


int moveUp(Map *map){
    int targetRow = (map-> playerRow)-1;
    int targetCol = (map-> playerCol);

    /* 0 if the move is valid and 1 if the move is invalid*/
    int condition = targetRow < 0 || map->type[targetRow][targetCol] == 1 || (map->type[targetRow][targetCol] == 2 && !map->treasureCollected);
    
    playerMovement(map, targetRow, targetCol, condition);
    return condition; 
}

int moveDown(Map *map){
    int targetRow = (map-> playerRow)+1;
    int targetCol = (map-> playerCol);

    /* 0 if the move is valid and 1 if the move is invalid*/
    int condition = targetRow >= (map->rows) || map->type[targetRow][targetCol] == 1 || (map->type[targetRow][targetCol] == 2 && !map->treasureCollected);
    
    playerMovement(map, targetRow, targetCol, condition);
    return condition;

}

int moveLeft(Map *map){
    int targetRow = (map-> playerRow);
    int targetCol = (map-> playerCol)-1;

    /* 0 if the move is valid and 1 if the move is invalid*/
    int condition = targetCol < 0 || map->type[targetRow][targetCol] == 1 || (map->type[targetRow][targetCol] == 2 && !map->treasureCollected);
    
    playerMovement(map, targetRow, targetCol, condition);
    return condition;
}

int moveRight(Map *map){
    int targetRow = (map-> playerRow);
    int targetCol = (map-> playerCol)+1;

    /* 0 if the move is valid and 1 if the move is invalid*/
    int condition = targetCol >= (map->cols) || map->type[targetRow][targetCol] == 1 || (map->type[targetRow][targetCol] == 2 && !map->treasureCollected);
    
    playerMovement(map, targetRow, targetCol, condition);
    return condition;
}

int playerMovement(Map *map, int targetRow, int targetCol, int condition){

    int oldRow = map->playerRow;   /* save old position */
    int oldCol = map->playerCol;   /* save old position */

    if(condition == 0){

        map-> grid[oldRow][oldCol] = ' '; /* used character value as the grid itself is a character*/
        map-> type[oldRow][oldCol] = 0;
        treasureCollected(map, targetRow, targetCol);
        map-> grid[targetRow][targetCol] = 'P'; /* new player position*/
        map-> type[targetRow][targetCol] = 4;

        /* Updating playerRow and playerCol */
        map->playerRow = targetRow;
        map->playerCol = targetCol;
    }

    return condition; 
}


/* Checks if the targetted block is the treasure block */
void treasureCollected(Map *map, int targetRow, int targetCol){

    if(map-> type[targetRow][targetCol] == 3){
        map-> treasureCollected = 1;
    }
}