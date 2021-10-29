#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define INS_SORT_SIZE 20

typedef struct
{
    unsigned int score;
    float data[3];
    char comments[16];
} ELEMENT;

typedef int _Cmpfun(const void *, const void *);
void swap(char*, char*, size_t);
void qsort_orig(void*, size_t, size_t, _Cmpfun);
void qsort_median_insert(void*, size_t, size_t, _Cmpfun);
void qsort_median_insert_iter(void*, size_t, size_t, _Cmpfun);