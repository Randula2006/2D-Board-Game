#include <stdio.h>
#include <stdlib.h>
#include "enemy.h"
#include "random.h"
#include "map.h"

int checkValidityOfCell(int cellType){
    int validity; /* 1 means valid and 0 means invalid */

    if(cellType == 1 || cellType == 3 || cellType == 2){
        validity = 0;
    }else{
        validity = 1;
    }

    return validity;
}

/* Relative direction from the facing direction */
void movement(Map *map){
    int tarForRow, tarForCol;
    int tarBackRow, tarBackCol;
    int tarLeftRow, tarLeftCol;
    int tarRightRow, tarRightCol;
    
    int forward, backward, left, right;
    char enemyFacingDirection = map-> grid[map-> enemyRow][map-> enemyCol];


    if(enemyFacingDirection == '∧'){
        forward = getCellFacing(map, -1, 0, &tarForRow, &tarForCol);
        backward = getCellFacing(map, +1, 0, &tarBackRow, &tarBackCol);
        left = getCellFacing(map, 0, -1, &tarLeftRow, &tarLeftCol);
        right = getCellFacing(map, 0, +1, &tarRightRow, &tarRightCol);

    }else if(enemyFacingDirection == 'v'){
        forward = getCellFacing(map, +1, 0, &tarForRow, &tarForCol);
        backward = getCellFacing(map, -1, 0, &tarBackRow, &tarBackCol);
        left = getCellFacing(map, 0, +1, &tarLeftRow, &tarLeftCol);
        right = getCellFacing(map, 0, -1, &tarRightRow, &tarRightCol);

    }else if(enemyFacingDirection == '<'){
        forward = getCellFacing(map, 0, -1, &tarForRow, &tarForCol);
        backward = getCellFacing(map, 0, +1, &tarBackRow, &tarBackCol);
        left = getCellFacing(map, -1, 0, &tarLeftRow, &tarLeftCol);
        right = getCellFacing(map, +1, 0, &tarRightRow, &tarRightCol);

    }else if(enemyFacingDirection == '>'){        
        forward = getCellFacing(map, 0, +1, &tarForRow, &tarForCol);
        backward = getCellFacing(map, 0, -1, &tarBackRow, &tarBackCol);
        left = getCellFacing(map, +1, 0, &tarLeftRow, &tarLeftCol);
        right = getCellFacing(map, -1, 0, &tarRightRow, &tarRightCol);

    }else{
        printf("Error in the character facing direction:\n");
    }
}


/* Facing ∧ */
int getCellFacing(Map *map, int x , int y, int *targetRow, int *targetCol){ /* Get cell while facing up*/
    *targetRow = (map-> enemyRow) + x;
    *targetCol = (map-> enemyCol) + y;
    return checkValidityOfCell(map-> type[*targetRow][*targetCol]);
}
