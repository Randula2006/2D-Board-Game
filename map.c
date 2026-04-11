#include <stdio.h>

char ** allocateGrid(int rows, int cols){
    int i;

    char ** grid = (char **) malloc(rows * sizeof(char *));
    for(i = 0; i < rows; i++){
        grid[i] = (char *) malloc(cols * sizeof(char *));
    }

    return grid;
}

/* references :- https://www.geeksforgeeks.org/c/c-program-to-read-contents-of-whole-file/ */
void createMap(){
    /* special Object variables*/
    int plyRow, plyCol, enemyRow, enemyCol, treRow, treCol, goalRow, goalCol;

    FILE * fptr = fopen("fileName.txt", "r");

    /*variables for data storing*/
    char values[20];
    int rows, cols;
    
    /* Read first line data of the file in specific format */
    fscanf(fptr, "%d %d", &rows , &cols);

    /* Initialize Map */
    char **grid = allocateGrid(rows, cols);

    /* read the rest of the file */
    int i,j, item;
    for (i = 0; i < rows; i++){
        for (j = 0; j < cols; j++){
            fscanf(fptr, "%d", &item);
            grid[i][j] = convertToChar(item);

            /* Record the special objects */
            if(item == 4){plyRow = i; plyCol = j;}
            if(item == 5){enemyRow = i; enemyCol = j;}
            if(item == 3){treRow = i; treCol = j;}
            if(item == 2){goalRow = i; goalCol = j;}

        }
    }

    fclose(fptr);
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