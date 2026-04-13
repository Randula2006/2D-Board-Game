#ifndef ENEMY_H
#define ENEMY_H

#include "map.h";

void enemyMovement(Map *map);
void getForwardCell(Map *map, int * targetRow, int * targetCol, int * targetValidity);
void getBackwardCell(Map *map, int * targetRow, int * targetCol, int * targetValidity);
void getLeftCell(Map *map, int * targetRow, int * targetCol, int * targetValidity);
void getRightCell(Map *map, int * targetRow, int * targetCol, int * targetValidity);
int checkValidityOfCell(int cellType);

#endif /* ENEMY_H */