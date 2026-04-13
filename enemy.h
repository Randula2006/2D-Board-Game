#ifndef ENEMY_H
#define ENEMY_H

#include "map.h";

void movement(Map *map);
int getCellFacing(Map *map, int x, int y, int *targetRow, int *targetCol);
int checkValidityOfCell(int cellType);

#endif /* ENEMY_H */