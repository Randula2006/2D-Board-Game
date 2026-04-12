
#include <stdio.h>
#include <stdlib.h>
#include "map.h"

int main(int argc, char *argv[])
{
    Map *map;

    if (argc != 2)
    {
        printf("Usage: ./labyrinth <map_file>\n");
        return 1;
    }

    system("cls"); /* clear once at the start */
    map = createMap(argv[1]);
    printMap(map);
    freeMap(map);
    return 0;
}