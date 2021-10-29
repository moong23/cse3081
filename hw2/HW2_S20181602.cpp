#include "my_quick_sorts.h"

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
    FILE *fp;
    int func, num, i, j;
    char input[20], output[20];
    ELEMENT *Arr;
    clock_t begin, end;

    fp = fopen("HW2_commands.txt", "r");
    if (!fp)
    {
        printf("error!\n");
        return -1;
    }
    fscanf(fp, "%d%d%s%s", &func, &num, input, output);

    Arr = (ELEMENT *)malloc(sizeof(ELEMENT) * num);

    srand(time(NULL));
    for (i = 0; i < num; i++)
    {
        Arr[i].score = rand() % 1000;
    }

    switch (func)
    {
    case 1:
        begin = clock();
        qsort(Arr, num, sizeof(ELEMENT), cmp);
        end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("time used while execution: %lf\n", time_spent);
        break;
    case 21:
        //qsort_orig();
        puts("qsort_orig");
        break;
    case 22:
        //qsort_median_insert();
        puts("qsort_median_insert");
        break;
    case 23:
        //qsort_median_insert_iter();
        puts("qsort_median_insert_iter");
        break;
    default:
        puts("wrong input");
        break;
    }

    return 0;
}