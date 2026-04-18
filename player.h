#ifndef PLAYER_H
#define PLAYER_H

#include "map.h" 

int movePlayer(Map *map, char input);
int playerMovement(Map *map, int targetRow, int targetCol, int condition);
int moveUp(Map *map);
int moveDown(Map *map);
int moveLeft(Map *map);
int moveRight(Map *map);
void treasureCollected(Map *map, int targetRow, int targetCol);

#endif /* PLAYER_H */