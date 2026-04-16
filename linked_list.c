#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "map.h"

LinkedList * createList(){
    LinkedList * list = (LinkedList *) malloc(sizeof(LinkedList));

    list-> head = NULL;
    list-> size = 0;

    return list;
}


void saveState(LinkedList * list, Map *map){
    int i,j;

    int **saveStateType = (int **)malloc(map->rows * sizeof(int *));
    char **saveStateGrid = (char **)malloc(map->rows * sizeof(char *));
    GameState * snapshot = (GameState *) malloc(sizeof(GameState));


    for (i = 0; i < map->rows; i++){
        saveStateGrid[i] = (char *)malloc(map->cols * sizeof(char));
    }

    for (i = 0; i < map->rows; i++){
        saveStateType[i] = (int *)malloc(map->cols * sizeof(int));
    }

    /* Setting variables to Game state */
    snapshot-> playerRow = map-> playerRow;
    snapshot-> playerCol = map-> playerCol;
    snapshot-> enemyRow = map-> enemyRow;
    snapshot-> enemyCol = map-> enemyCol;
    snapshot-> treasureCollected = map-> treasureCollected;
    snapshot-> enemyFacing = map-> grid[map->enemyRow][map->enemyCol];


    /* setting variables to Node */
    node-> data = snapshot;
    node-> next = list-> head;
    list-> head = node;
    list-> size++; /* Increase the pointer size*/


    for(i = 0; i < map->rows; i++){
        for(j = 0; j < map->cols; j++){
            saveStateGrid[i][j] = map-> grid[i][j];
        }
    }

    for (i = 0; i < map->rows; i++){
        for (j = 0; j < map->cols; j++){
            saveStateType[i][j] = map->type[i][j];
        }
    }

    snapshot-> grid = saveStateGrid;
    snapshot-> type = saveStateType;

    /* Finish the */
    Node * node = (Node *) malloc(sizeof(Node));
}


/* Reference: https://www.geeksforgeeks.org/c/stack-using-linked-list-in-c/ */
/* Function to create a new node and push it into the stack */
struct Node *push(struct Node *top, void * data){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode-> data = data;
    newNode-> next = top;
    top = newNode;
    
    
    return top;
}



