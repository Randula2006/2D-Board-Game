#ifndef ENEMY_H
#define ENEMY_H

#include "map.h";

int checkValidityOfCell(int cellType);
void movement(Map *map);
int getCellFacing(Map *map, int x , int y, int *targetRow, int *targetCol);
void enemyMove(Map *map, int targetRow, int targetCol, char facingDirection);
char rotateEnemy(char currentFacing, char rotationSide);
void controlEnemyMovement(Map *map, int condition);

#endif /* ENEMY_H */