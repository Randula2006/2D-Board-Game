#include <stdio.h>
#include <stdlib.h>
#include "enemy.h"
#include "map.h"


void enemyMovement(){
    Map * map;

    int tarForRow, tarForCol, tarForValidity;
    int tarBackRow, tarBackCol, tarBackValidity;
    int tarLeftRow, tarLeftCol, tarLeftValidity;
    int tarRightRow, tarRightCol, tarRightValidity;

    getForwardCell(map, &tarForRow, &tarForCol, &tarForValidity);
    getBackwardCell(map, &tarBackRow, &tarBackCol, &tarBackValidity);
    getLeftCell(map, &tarLeftRow, &tarLeftCol, &tarLeftValidity);
    getRightCell(map, &tarRightRow, &tarRightCol, &tarRightValidity);



}

void getForwardCell(Map *map, int * targetRow, int * targetCol, int * targetValidity){
    int targetRow = (map-> enemyRow)-1;
    int targetCol = (map-> enemyCol);
    targetValidity = map-> type[targetRow][targetCol];
}

void getBackwardCell(Map *map, int * targetRow, int * targetCol, int * targetValidity){
    int targetRow = (map-> enemyRow)+1;
    int targetCol = (map-> enemyCol);
    targetValidity = map-> type[targetRow][targetCol];
}

void getLeftCell(Map *map, int * targetRow, int * targetCol, int * targetValidity){
    int targetRow = (map-> playerRow);
    int targetCol = (map-> playerCol)-1;
    targetValidity = map-> type[targetRow][targetCol];
}

void getRightCell(Map *map, int * targetRow, int * targetCol, int * targetValidity){
    int targetRow = (map-> playerRow);
    int targetCol = (map-> playerCol)+1;
    targetValidity = map-> type[targetRow][targetCol];
}

int checkValidityOfCell(){
    /* TODO: do the validation for the targetted block */
}