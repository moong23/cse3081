#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct
{
    unsigned int score;
    float data[3];
    char comments[16];
} ELEMENT;

typedef int _Cmpfun(const void *, const void *);
