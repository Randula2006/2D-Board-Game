#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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

#endif /* LINKED_LIST_H */