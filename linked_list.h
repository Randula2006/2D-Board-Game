#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "map.h"

typedef struct {
    int playerRow, playerCol;
    int enemyRow, enemyCol;
    int treasureCollected;
    char enemyFacing;
    char ** grid;
    int ** type;
} GameState;


typedef struct Node{
    void * data; /* Genaric pointer to store the GameState */
    struct Node *next;
}Node;


typedef struct{
    Node * head;
    int size;
} LinkedList;


LinkedList * createList();
void saveState(LinkedList * list, Map * map);
void restoreState(LinkedList * list, Map * map);
void freeList(LinkedList * list, Map * map);

#endif /* LINKED_LIST_H */