#include<stdlib.h>
#include<time.h>
#include"random.h"

/* Reference: supplymentary video UCP*/
/* call at the main function at the start of the program*/
void initRandom()
{
    srand(time(NULL));
}


/* Reference: supplymentary video UCP*/
/* will retrun a random number between the low and the high including them */
int randomNumber(int low, int high)
{
    int number = -1;

    if(low <= high)
    {
        number = (rand() % (high-low+1)) + low;
    }

    return number;
}