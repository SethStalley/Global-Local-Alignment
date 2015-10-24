#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int globalAlignment(char* , char*);
int localAlignment(char*, char*);


typedef struct matrixcell
{
    int val;
    
    // Where the arrow of movement came from
    int origin_direction_arrow_i;
    int origin_direction_arrow_j;
    
    
} mcell_t;