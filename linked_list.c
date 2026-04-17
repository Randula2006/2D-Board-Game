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


void saveState(LinkedList * list, Map * map){
    int i,j;
    Node * node;
    GameState * snapshot;
    int **saveStateType = (int **)malloc(map->rows * sizeof(int *));
    char **saveStateGrid = (char **)malloc(map->rows * sizeof(char *));
    
    snapshot = (GameState *) malloc(sizeof(GameState));


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

    /* Deep copying grid and type */
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

    /* Finish then create the new Node*/
    node = (Node *) malloc(sizeof(Node));

    /* setting variables to Node */
    node-> data = snapshot;
    node-> next = list-> head;
    list-> head = node;
    list-> size++; /* Increase the pointer size*/

    
}


void restoreState(LinkedList * list, Map * map){
    int i, j;
    Node * temp;
    GameState * state;

    /* check if the list is empty */
    if(list-> head != NULL){
        temp = list-> head;
        state = (GameState *) temp-> data;

        /* Restore simple variables */
        map-> playerRow = state-> playerRow;
        map-> playerCol = state-> playerCol;
        map-> enemyRow = state-> enemyRow;
        map-> enemyCol = state-> enemyCol;
        map-> treasureCollected = state-> treasureCollected;
        map-> grid[state->enemyRow][state->enemyCol] = state-> enemyFacing;

        for(i = 0; i < map->rows; i++){
            for(j = 0; j < map->cols; j++){
                map->grid[i][j] = state->grid[i][j];
            }
        }

        for (i = 0; i < map->rows; i++){
            for (j = 0; j < map->cols; j++){
                map->type[i][j] = state->type[i][j];
            }
        }

        /* Freeing the malloc from used by the grid and the type */
        /* Free the grid */
        for(i = 0; i < map->rows; i++){
            free(state->grid[i]);
        }
        free(state->grid);

        /* Free the type */
        for (i = 0; i < map->rows; i++)
        {
            free(state->type[i]);
        }
        free(state->type);

        /* Finally free the game-state */
        free(state);

        /* Move head forward */
        list->head = temp->next;

        /* Free the node*/
        free(temp);

        list-> size--;
    }

}


void freeList(LinkedList * list, Map * map){
    int i;
    Node * temp;
    Node * nextNode;
    GameState * state;

    temp = list-> head;


    /* Freeing the malloc from used by the grid and the type */
    /* Free the grid */
    while(temp != NULL){
        
        nextNode = temp-> next;
        state = (GameState *) temp->data;

        for (i = 0; i < map->rows; i++)
        {
            free(state->grid[i]);
        }
        free(state->grid);

        /* Free the type */
        for (i = 0; i < map->rows; i++)
        {
            free(state->type[i]);
        }
        free(state->type);

        /* Finally free the game-state */
        free(state);

        free(temp);
        temp = nextNode;
    }

    /* Setting values to 0 before freeing up the list */
    list-> head = NULL;
    list-> size = 0;
    free(list);

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

