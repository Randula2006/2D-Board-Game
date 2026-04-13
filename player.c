#include <stdlib.h>
#include <stdio.h>
#include "player.h"
#include "map.h"

int movePlayer(Map *map, char input){

    int playerMoved;

    if(input == 'w'){
        playerMoved = moveUp(map);
    }else if(input == 'a'){
        playerMoved = moveLeft(map);
    }else if(input == 's'){
        playerMoved = moveDown(map);
    }else if(input == 'd'){
        playerMoved = moveRight(map);
    }else{
        playerMoved = 0;
    }


    return playerMoved;
}


int moveUp(Map *map){
    int targetRow = (map-> playerRow)-1;
    int targetCol = (map-> playerCol);

    /* 1 if the move is valid and 0 if the move is invalid*/
    int condition = targetRow < 0 || map->type[targetRow][targetCol] == 1 || (map->type[targetRow][targetCol] == 2 && !map->treasureCollected);
    
    int result = playerMovement(map, targetRow, targetCol, condition);
    return result; 
}

int moveDown(Map *map){
    int targetRow = (map-> playerRow)+1;
    int targetCol = (map-> playerCol);

    /* 1 if the move is valid and 0 if the move is invalid*/
    int condition = targetRow >= (map->rows) || map->type[targetRow][targetCol] == 1 || (map->type[targetRow][targetCol] == 2 && !map->treasureCollected);
    
    int result = playerMovement(map, targetRow, targetCol, condition);
    return result;

}

int moveLeft(Map *map){
    int targetRow = (map-> playerRow);
    int targetCol = (map-> playerCol)-1;

    /* 1 if the move is valid and 0 if the move is invalid*/
    int condition = targetCol < 0 || map->type[targetRow][targetCol] == 1 || (map->type[targetRow][targetCol] == 2 && !map->treasureCollected);
    
    int result = playerMovement(map, targetRow, targetCol, condition);
    return result;
}

int moveRight(Map *map){
    int targetRow = (map-> playerRow);
    int targetCol = (map-> playerCol)+1;

    /* 1 if the move is valid and 0 if the move is invalid*/
    int condition = targetCol >= (map->cols) || map->type[targetRow][targetCol] == 1 || (map->type[targetRow][targetCol] == 2 && !map->treasureCollected);
    
    int result = playerMovement(map, targetRow, targetCol, condition);
    return result;
}

int playerMovement(Map *map, int targetRow, int targetCol, int condition){

    int oldRow = map->playerRow;   /* save old position */
    int oldCol = map->playerCol;   /* save old position */
    int result;

    /* 1 if the move is valid and 0 if the move is invalid*/
    if(condition){
        result = 0;
    }else{
        result = 1;
    }

    if(result == 1){

        map-> grid[oldRow][oldCol] = ' '; /* used character value as the grid itself is a character*/
        map-> type[oldRow][oldCol] = 0;
        treasureCollected(map, targetRow, targetCol);
        map-> grid[targetRow][targetCol] = 'P'; /* new player position*/
        map-> type[targetRow][targetCol] = 4;

        /* Updating playerRow and playerCol */
        map->playerRow = targetRow;
        map->playerCol = targetCol;
    }

    return result; 
}



/* Checks if the targetted block is the treasure block */
void treasureCollected(Map *map, int targetRow, int targetCol){

    if(map-> type[targetRow][targetCol] == 3){
        map-> treasureCollected = 1;
    }
}