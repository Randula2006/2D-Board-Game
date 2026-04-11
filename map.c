#include <stdio.h>
#include <stdlib.h>
#include "map.h"

char ** allocateGrid(int rows, int cols){
    int i;

    char ** grid = (char **) malloc(rows * sizeof(char *));
    for(i = 0; i < rows; i++){
        grid[i] = (char *) malloc(cols * sizeof(char *));
    }

    return grid;
}

/* references :- https://www.geeksforgeeks.org/c/c-program-to-read-contents-of-whole-file/ */
Map * createMap(){

    FILE * fptr = fopen("fileName.txt", "r");
    Map *map;

    /* Allocate the Map struct itself */
    map = (Map *)malloc(sizeof(Map));
    map->treasureCollected = 0;
    
    /* EXCEPTION :- if the file is NULL*/
    if (fptr == NULL)
    {
        printf("Error: could not open file %s\n");
        return NULL;
    }

    /* Read dimensions into the struct directly */
    fscanf(fptr, "%d %d", &map-> rows , &map-> cols);

    /* Initialize Map store the grid into the struct */
    map-> grid = allocateGrid(&map-> rows , &map-> cols);

    /* read the rest of the file */
    int i,j, item;
    for (i = 0; i < map->rows; i++){
        for (j = 0; j < map->cols; j++){
            fscanf(fptr, "%d", &item);
            map->grid[i][j] = convertToChar(item);

            /* Record the special objects */
            if(item == 4){map->playerRow = i; map->playerCol = j;}
            if(item == 5){map->enemyRow = i; map->enemyCol = j;}
            if(item == 3){map->treasureRow = i; map->treasureCol = j;}
            if(item == 2){map->goalRow = i; map->goalCol = j;}

        }
    }

    fclose(fptr);
    return map; /* return the map to the called function*/
}

char convertToChar(int item){
    char object;
    if(item == 0){
        object =  ' '; /* Empty space */
    }else if(item == 1){
        object = ' '; /* Wall :- same char diffrent color*/
    }else if (item == 2){
        object = 'G';
    }else if (item == 3){
        object = 'T';
    }else if (item == 4){
        object = 'P';
    }else{
        object = '<';
    }

    return object;
}

