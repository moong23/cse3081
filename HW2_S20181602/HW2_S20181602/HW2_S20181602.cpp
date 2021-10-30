#include "my_quick_sorts.h"
//#define PRINT_ARRAY

int cmp(const void *a, const void *b)
{
    ELEMENT *n_a, *n_b;
    n_a = (ELEMENT *)a;
    n_b = (ELEMENT *)b;

    return n_a->score > n_b->score ? 1 : n_a->score < n_b->score ? -1
                                                                 : 0;
}

int main()
{
    FILE* fp;
    int func, num, i, j;
    char input[20], output[20];
    double time_spent;
    ELEMENT* Arr;
    clock_t begin = 0, end = 0;

    fp = fopen("HW2_commands.txt", "r");
    if (!fp)
    {
        printf("can't find input!\n");
        return -1;
    }
    fscanf(fp, "%d%d%s%s", &func, &num, input, output);

    Arr = (ELEMENT*)malloc(sizeof(ELEMENT) * num);

    srand(time(NULL));
    for (i = 0; i < num; i++)
    {
        Arr[i].score = rand() % 100000;
    }
    /*
    for (i = 0; i < 100; i++) {
        printf("%d ", Arr[i].score);
    }
    */
    switch (func)
    {
    case 1:
        begin = clock();
        qsort(Arr, num, sizeof(ELEMENT), cmp);
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("time used while execution: %lf\n", time_spent);
#ifdef PRINT_ARRAY
        for (i = 0; i < MAX_STRING; i++) {
            printf("%d ", Arr[i].score);
        }
#endif
        break;
    case 21:
        begin = clock();
        qsort_orig(Arr, num, sizeof(ELEMENT), cmp);
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("time used while execution: %lf\n", time_spent);
#ifdef PRINT_ARRAY
        for (i = 0; i < MAX_STRING; i++) {
            printf("%d ", Arr[i].score);
        }
#endif
        break;
    case 22:
        begin = clock();
        qsort_median_insert(Arr, num, sizeof(ELEMENT), cmp);
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("time used while execution: %lf\n", time_spent);
#ifdef PRINT_ARRAY
        for (i = 0; i < num; i++) {
            printf("%d :%u\n", i,Arr[i].score);
        }
#endif
        break;
    case 23:
        begin = clock();
        qsort_median_insert_iter(Arr, num, sizeof(ELEMENT), cmp);
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("time used while execution: %lf\n", time_spent);
#ifdef PRINT_ARRAY
        for (i = 0; i < num; i++) {
            printf("%d : %u\n", i+1,Arr[i].score);
        }
#endif
        break;
    default:
        puts("wrong input");
        return -1;
    }
    return 0;
}