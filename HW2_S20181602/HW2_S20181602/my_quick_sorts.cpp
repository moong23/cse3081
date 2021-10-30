#include "my_quick_sorts.h"

void swap(char *x, char *y, size_t size)
{
	char buf[512];
	size_t m, ms;
	for (ms = size; ms > 0; ms -= m, x += m, y += m)
	{
		m = (ms < sizeof(buf)) ? ms : sizeof(buf);
		memcpy(buf, x, m);
		memcpy(x, y, m);
		memcpy(y, buf, m);
	}
}

size_t partition(void *Arr, size_t n, size_t size, _Cmpfun *cmp)
{
	char *S = (char *)Arr;
	char *tmp = (char *)malloc(sizeof(char) * size);
	size_t i = 0, k = 0;
	memcpy(tmp, S, size);
	swap(S, S + (n - 1) * size, size);
	for (i = 0; i < (n - 1) * size; i += size)
	{
		if ((*cmp)(tmp, S + i) >= 0)
		{
			swap(S + k * size, S + i, size);
			k++;
		}
	}
	swap(S + (n - 1) * size, S + k * size, size);
	free(tmp);
	return k;
}

size_t piv_partition(void *Arr, size_t n, size_t size, _Cmpfun *cmp, size_t pivot)
{
	char *S = (char *)Arr;
	char *tmp = (char *)malloc(sizeof(char) * size);
	size_t i = 0, k = 0;
	memcpy(tmp, S + pivot * size, size);
	swap(S + pivot * size, S + (n - 1) * size, size);
	for (i = 0; i < (n - 1) * size; i += size)
	{
		if ((*cmp)(tmp, S + i) >= 0)
		{
			swap(S + k * size, S + i, size);
			k++;
		}
	}
	swap(S + (n - 1) * size, S + k * size, size);
	free(tmp);
	return k;
}

// function 21
void qsort_orig(void *Arr, size_t n, size_t size, _Cmpfun *cmp)
{
	char *S = (char *)Arr;
	size_t pivot;
	if (n > 1)
	{
		pivot = partition(S, n, size, cmp); // set pivot

		qsort_orig(S, pivot, size, cmp);
		qsort_orig(S + (pivot + 1) * size, n - 1 - pivot, size, cmp);
	}
	return;
}

void insertion_sort(void *Arr, size_t n, size_t size, _Cmpfun *cmp)
{
	char *S = (char *)Arr;
	char *tmp = (char *)malloc(size);
	size_t i = 0, j = 0;

	i = 0;
	while (i < n * size)
	{
		memcpy(tmp, S + i, size);
		for (j = i - size; j >= 0; j -= size)
		{
			if (i == 0)
				break;

			if ((*cmp)(tmp, S + j) < 0)
			{
				memcpy(S + (j + size), S + j, size);
			}
			else
			{
				j -= size;
				break;
			}
			memcpy(S + j, tmp, size);
			if (j == 0)
				break;
		}
		i += size;
	}
}

// function 22
void qsort_median_insert(void *Arr, size_t n, size_t size, _Cmpfun *cmp)
{
	char *S = (char *)Arr;
	size_t pivot, a, b, c;

	if (n <= INS_SORT_SIZE)
	{
		insertion_sort(S, n, size, cmp);
		return;
	}
	// if array's size is small enough, function 22 will do insertion sort

	a = rand() % n;
	b = rand() % n;
	c = rand() % n;
	//randomly chosen 3 pivot variables
	pivot = a > b ? a > c ? b > c ? b : c : a : a < c ? b < c ? b : c
													  : a;
	//pivot is the middle-value one among those three.

	pivot = piv_partition(S, n, size, cmp, pivot);

	if (pivot)
		qsort_median_insert(S, pivot, size, cmp);
	if (n - 1 > pivot)
		qsort_median_insert(S + (pivot + 1) * size, n - 1 - pivot, size, cmp);
	return;
}

void qsort_median_insert_iter(void *Arr, size_t n, size_t size, _Cmpfun *cmp)
{
	char *S = (char *)Arr;
	size_t k = n - 1;
	size_t pivot, a, b, c;
	while (n > 0)
	{
		if (n < INS_SORT_SIZE)
		{
			insertion_sort(S, n, size, cmp);
			return;
		}
		// if array's size is small enough, function 22 will do insertion sort

		a = rand() % n;
		b = rand() % n;
		c = rand() % n;
		//randomly chosen 3 pivot variables
		pivot = a > b ? a > c ? b > c ? b : c : a : a < c ? b < c ? b : c
														  : a;
		//pivot is the middle-value one among those three.

		pivot = piv_partition(S, n, size, cmp, pivot);
		//smaller part recursive function
		if (pivot < n - pivot - 1)
		{
			if (pivot)
				qsort_median_insert_iter(S, pivot, size, cmp);
			n -= pivot + 1;
			S = S + (pivot + 1) * size;
		}
		//larger part iteration
		else
		{
			if (pivot < n - 1)
				qsort_median_insert_iter(S + (pivot + 1) * size, n - 1 - pivot, size, cmp);
			n = pivot;
		}
	}
	return;
}