#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "map.h"

char ** allocateGrid(int rows, int cols){
    int i;

    char ** grid = (char **) malloc(rows * sizeof(char *));
    for(i = 0; i < rows; i++){
        grid[i] = (char *) malloc(cols * sizeof(char));
    }

    return grid;
}

int **allocateType(int rows, int cols)
{
    int i;
    int **type = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++)
    {
        type[i] = (int *)malloc(cols * sizeof(int));
    }
    return type;
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


Map * createMap(const char *filename){
    int i,j, item;

    FILE *fptr;
    Map *map;

    /* Allocate the Map struct itself */
    map = (Map *)malloc(sizeof(Map));
    map->treasureCollected = 0;
    
    /* EXCEPTION :- if the file is NULL*/
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Error: could not open file %s\n", filename);
        return NULL;
    }

    /* Read dimensions into the struct directly */
    /* references :- https://www.geeksforgeeks.org/c/c-program-to-read-contents-of-whole-file/ */
    fscanf(fptr, "%d %d", &map-> rows , &map-> cols);

    /* Initialize Map store the grid into the struct */
    map-> grid = allocateGrid(map-> rows , map-> cols);
    map->type = allocateType(map->rows, map->cols);

    /* read the rest of the file */
    for (i = 0; i < map->rows; i++){
        for (j = 0; j < map->cols; j++){
            fscanf(fptr, "%d", &item);
            map->type[i][j] = item; 
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

void printMap(Map *map){
    int i,j;

    system("clear");    /* Reference :- Assignment supplementary video */
    /*Move cursor to top-lef coner*/
    system("tput cup 0 0");

    /* Printing Border */

    /* Starting asterisks */
    for(i = 0; i < (map-> cols)+2 ; i++){
        printf("*");
    }
    printf("\n");

    /* 2D array iteration */
    for (i = 0; i < map->rows; i++){
        printf("*");
        for (j = 0; j < map->cols; j++){
            if(map->grid[i][j] == ' ' && map->type[i][j] == 1){
                setBackground("white");
                printf("%c", map->grid[i][j]);
                setBackground("reset");
            }else if(map->grid[i][j] == 'G' && map->type[i][j] == 2){
                setBackground("green");
                printf("%c", map->grid[i][j]);
                setBackground("reset");
            }else if(map->grid[i][j] == 'T'){
                setBackground("yellow");
                printf("%c", map->grid[i][j]);
                setBackground("reset");
            }else if(map->grid[i][j] == 'P'){
                setForeground("blue");
                printf("%c", map->grid[i][j]);
                setForeground("reset");
            }else if(map->grid[i][j] == '<'){
                setForeground("red");
                printf("%c", map->grid[i][j]);
                setForeground("reset");
            }else{
                printf("%c", map->grid[i][j]);
                setBackground("reset");
                setForeground("reset");
            }

        }
        printf("*\n");
    }

    /* Ending asterisks*/
    for(i = 0; i < (map-> cols)+2 ; i++){
        printf("*");
    }

    fflush(stdout);
}

/* helper function for map printing*/
/* Reference :- Assignment supplementary video */

void freeMap(Map *map){

}




/* Set colors function */
void setForeground(char * color)
{
    if(strcmp(color, "black") == 0)
    {
        printf("\033[30m");
    }
    else if(strcmp(color, "red") == 0)
    {
        printf("\033[31m");
    }
    else if(strcmp(color, "blue") == 0)
    {
        printf("\033[34m");
    }
    else if(strcmp(color, "white") == 0)
    {
        printf("\033[37m");
    }
    else if(strcmp(color, "reset") == 0)
    {
        printf("\033[39m");
    }
}

void setBackground(char * color)
{
    if(strcmp(color, "black") == 0)
    {
        printf("\033[40m");
    }
    else if(strcmp(color, "green") == 0)
    {
        printf("\033[42m");
    }
    else if(strcmp(color, "yellow") == 0)
    {
        printf("\033[43m");
    }
    else if(strcmp(color, "white") == 0)
    {
        printf("\033[47m");
    }
    else if(strcmp(color, "reset") == 0)
    {
        printf("\033[49m");
    }
}