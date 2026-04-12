#ifndef MAP_H
#define MAP_H

typedef struct {
    char ** grid;
    int ** type;
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

int **allocateType(int rows, int cols);
char ** allocateGrid(int rows, int cols);

Map *createMap(const char *filename);
char convertToChar(int item);
void printMap(Map *map);

void freeMap(Map *map);
void setForeground(char * color);
void setBackground(char * color);

#endif /* MAP_H */