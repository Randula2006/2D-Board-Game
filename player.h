#ifndef PLAYER_H
#define PLAYER_H

#include "map.h" 

int movePlayer(Map *map, char input);
int moveUp(Map *map);
int moveDown(Map *map);
int moveLeft(Map *map);
int moveRight(Map *map);

#endif /* PLAYER_H */