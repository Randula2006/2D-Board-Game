#ifndef MAP_H
#define MAP_H

typedef struct {
    char ** grid;
    int rows;
    int cols;
    int playerRow;
    int plyerCol;
    int enemyRow;
    int emenyCol;
    int treasureRow;
    int treasureCol;
    int goalRow;
    int goalCol;
    int treasureCollected; /* yes = 1 no = 0 */

}Map;


#endif /* MAP_H */