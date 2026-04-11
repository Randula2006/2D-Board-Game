#ifndef MAP_H
#define MAP_H

typedef struct {
    char ** grid;
    int rows;
    int cols;
    int playerRow;
    int playerCol;
    int enemyRow;
    int enemyCol;
    int treasureRow;
    int treasureCol;
    int goalRow;
    int goalCol;
    int treasureCollected; /* yes = 1 no = 0 */

}Map;

Map *createMap();
char convertToChar(int item);
void freeMap(Map *map);

#endif /* MAP_H */