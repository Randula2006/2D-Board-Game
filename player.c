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
    int oldRow = map->playerRow;   /* save old position */
    int oldCol = map->playerCol;   /* save old position */
    int result;

    /* 1 if the move is valid and 0 if the move is invalid*/
    if( targetRow < 0 || map->type[targetRow][targetCol] == 1){
        result = 0;
    }else{
        result = 1;
    }

    if(result == 1){

        map-> grid[oldRow][oldCol] = ' '; /* used character value as the grid itself is a character*/
        map-> type[oldRow][oldCol] = 0;
        map-> grid[targetRow][targetCol] = 'P'; /* new player position*/
        map-> type[targetRow][targetCol] = 4;

        /* Updating playerRow and playerCol */
        map->playerRow = targetRow;
        map->playerCol = targetCol;
    }

    return result; 
}

int moveDown(Map *map){
    int targetRow = (map-> playerRow)+1;
    int targetCol = (map-> playerCol);
    int oldRow = map->playerRow;   /* save old position */
    int oldCol = map->playerCol;   /* save old position */
    int result;

    /* 1 if the move is valid and 0 if the move is invalid*/
    if( targetRow >= (map->rows) || map->type[targetRow][targetCol] == 1){
        result = 0;
    }else{
        result = 1;
    }

    if(result == 1){

        map-> grid[oldRow][oldCol] = ' '; /* used character value as the grid itself is a character*/
        map-> type[oldRow][oldCol] = 0;
        map-> grid[targetRow][targetCol] = 'P'; /* new player position*/
        map-> type[targetRow][targetCol] = 4;

        /* Updating playerRow and playerCol */
        map->playerRow = targetRow;
        map->playerCol = targetCol;
    }

    return result; 
}

int moveLeft(Map *map){
    int targetRow = (map-> playerRow);
    int targetCol = (map-> playerCol)-1;
    int oldRow = map->playerRow;   /* save old position */
    int oldCol = map->playerCol;   /* save old position */
    int result;

    /* 1 if the move is valid and 0 if the move is invalid*/
    if( targetCol < 0 || map->type[targetRow][targetCol] == 1){
        result = 0;
    }else{
        result = 1;
    }

    if(result == 1){

        map-> grid[oldRow][oldCol] = ' '; /* used character value as the grid itself is a character*/
        map-> type[oldRow][oldCol] = 0;
        map-> grid[targetRow][targetCol] = 'P'; /* new player position*/
        map-> type[targetRow][targetCol] = 4;

        /* Updating playerRow and playerCol */
        map->playerRow = targetRow;
        map->playerCol = targetCol;
    }

    return result; 
}

int moveRight(Map *map){
    int targetRow = (map-> playerRow);
    int targetCol = (map-> playerCol)+1;
    int oldRow = map->playerRow;   /* save old position */
    int oldCol = map->playerCol;   /* save old position */
    int result;

    /* 1 if the move is valid and 0 if the move is invalid*/
    if( targetCol >= (map->cols) || map->type[targetRow][targetCol] == 1){
        result = 0;
    }else{
        result = 1;
    }

    if(result == 1){

        map-> grid[oldRow][oldCol] = ' '; /* used character value as the grid itself is a character*/
        map-> type[oldRow][oldCol] = 0;
        map-> grid[targetRow][targetCol] = 'P'; /* new player position*/
        map-> type[targetRow][targetCol] = 4;

        /* Updating playerRow and playerCol */
        map->playerRow = targetRow;
        map->playerCol = targetCol;
    }

    return result; 
}