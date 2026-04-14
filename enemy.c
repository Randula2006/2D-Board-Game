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
    int direction; /* random number value given by randomNumber function */
    char enemyFacingDirection = map-> grid[map-> enemyRow][map-> enemyCol];    /* getting enemy facing direction each time the function runs */


    if(enemyFacingDirection == '^'){
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


/*--------------------- cases that the enemy can move ---------------------------*/
   
    /* case-1 : forward free.both sides are blocked - move forward ,no rotations*/
    if(forward == 1 && left == 0 && right == 0){
        enemyMove(map, tarForRow, tarForCol, enemyFacingDirection); /* current enemy facing direction*/
    }

    /* case-2 : forward free. at least one side is free. intersection.RNG choose*/
    else if (forward == 1 && (left == 1 || right == 1)){
        if(left == 1 && right == 1){ /* all three paths are available*/
            direction = randomNumber(0, 2);

            /* Setting the path*/
            if(direction == 0){
                enemyMove(map, tarForRow, tarForCol, enemyFacingDirection);
            }else if(direction == 1){ /* turn left */
                enemyMove(map, tarLeftRow, tarLeftCol, rotateEnemy(enemyFacingDirection, 'L'));
            }else{ /* turn right */
                enemyMove(map, tarRightRow, tarRightCol, rotateEnemy(enemyFacingDirection, 'R'));
            }

        }else{

            direction = randomNumber(0, 1); /* only two paths are available */

            if(direction == 0){
                enemyMove(map, tarForRow, tarForCol, enemyFacingDirection); 
            }else if(direction == 1 && left == 1){ /* First check if left is avaible and if not go to right*/
                enemyMove(map, tarLeftRow, tarLeftCol, rotateEnemy(enemyFacingDirection, 'L'));
            }else{
                enemyMove(map, tarRightRow, tarRightCol, rotateEnemy(enemyFacingDirection, 'R'));  
            }
        }
    }

    /* case-3 : forward blocked. all sides free. RNG choose. */
    else if(forward == 0 && left == 1 && right == 1){
        direction = randomNumber(0, 1);

        if(direction == 0){/* Move Left*/
            enemyMove(map, tarLeftRow, tarLeftCol, rotateEnemy(enemyFacingDirection, 'L'));
        }else{
            enemyMove(map, tarRightRow, tarRightCol, rotateEnemy(enemyFacingDirection, 'R'));       
        }

    }

    /* case-4: forward blocked. one side free. rotate to that side */
    else if (forward == 0 && (left == 1 || right == 1)){
        if(left == 1){
            enemyMove(map, tarLeftRow, tarLeftCol, rotateEnemy(enemyFacingDirection, 'L'));            
        }else{
            enemyMove(map, tarRightRow, tarRightCol, rotateEnemy(enemyFacingDirection, 'R')); 
        }
    }

    /* case-5: all sides are blocked. 180 rotation. */
    else if(forward == 0 && left == 0 && right == 0){
        enemyMove(map, tarBackRow, tarBackCol,rotateEnemy(enemyFacingDirection, 'B'));
    }
    /* If an Exception occur in the system */
    else{
        printf("Exception:- not a valid move");
    }
}

/* getting next block information from the Facing direction */
int getCellFacing(Map *map, int x , int y, int *targetRow, int *targetCol){ /* Get cell while facing up*/
    int result;
    *targetRow = (map-> enemyRow) + x;
    *targetCol = (map-> enemyCol) + y;

    /* check boundaries first before accessing type array */
    if(*targetRow < 0 || *targetRow >= map->rows || 
       *targetCol < 0 || *targetCol >= map->cols){
        result = 0; /* treat out of bounds as blocked */
    }else{
        result = checkValidityOfCell(map-> type[*targetRow][*targetCol]);
    }

    return result;
}


/* function to update the grid when enemy move */
void enemyMove(Map *map, int targetRow, int targetCol, char facingDirection){
    int oldRow = map->enemyRow;   /* save old position */
    int oldCol = map->enemyCol;   /* save old position */

    map->grid[oldRow][oldCol] = ' '; /* used character value as the grid itself is a character*/
    map->type[oldRow][oldCol] = 0;
    setForeground("red");
    map->grid[targetRow][targetCol] = facingDirection; /* new enemy position*/
    setForeground("reset");
    map->type[targetRow][targetCol] = 5;

    /* Updating enemyRow and enemyCol */
    map->enemyRow = targetRow;
    map->enemyCol = targetCol;
}

char rotateEnemy(char currentFacing, char rotationSide){
    char facingDirection;
    switch (rotationSide)
    {
    case 'L':
        if(currentFacing == '^'){facingDirection = '<';}
        if(currentFacing == '<'){facingDirection = 'v';}
        if(currentFacing == 'v'){facingDirection = '>';}
        if(currentFacing == '>'){facingDirection = '^';}
        break;

    case 'R':
        if(currentFacing == '^'){facingDirection = '>';}
        if(currentFacing == '<'){facingDirection = '^';}
        if(currentFacing == 'v'){facingDirection = '<';}
        if(currentFacing == '>'){facingDirection = 'v';}
        break;

    case 'B':
        if(currentFacing == '^'){facingDirection = 'v';}
        if(currentFacing == '<'){facingDirection = '>';}
        if(currentFacing == 'v'){facingDirection = '^';}
        if(currentFacing == '>'){facingDirection = '<';}
        break;

    default:
        printf("exception: error getting the enemy Side.");
        break;
    }

    return facingDirection;
}

/* Enemy movement depending on treasure collected or not */
void controlEnemyMovement(Map *map, int condition){
    if(map->treasureCollected == 0 && condition == 0){ /* move 2 times if treasure is not collected and player movement is valid */
        movement(map);
        movement(map);
    }else if(map->treasureCollected == 1 && condition == 0){ /* move 3 times if treaure is collected and player movement is valid */
        movement(map);
        movement(map);
        movement(map);
    }else{
        /* Do nothing as the player movement is invalid. */
    }
}
