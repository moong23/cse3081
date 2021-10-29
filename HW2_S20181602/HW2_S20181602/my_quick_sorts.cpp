#include "my_quick_sorts.h"

void swap(char* x, char* y, size_t size) {
	char buf[512];
	size_t m, ms;
	for (ms = size; ms > 0; ms -= m, x += m, y += m) {
		m = (ms < sizeof(buf)) ? ms : sizeof(buf);
		memcpy(buf, x, m);
		memcpy(x, y, m);
		memcpy(y, buf, m);
	}
}

size_t partition(void* Arr, size_t n, size_t size, _Cmpfun* cmp, size_t pivot) {
	char* S = (char*)Arr;
	char* p = (char*)malloc(sizeof(char) * size);
	size_t i = 0, k = 0;
	memcpy(p, S + pivot * size, size);
	swap(S + pivot * size, S + (n - 1) * size, size);
	for (i = 0; i < (n - 1) * size; i += size) {
		if ((*cmp)(S + i, p) <= 0) {
			swap(S + k * size, S + i, size);
			k++;
		}
	}
	swap(S + (n - 1) * size, S + k * size, size);
	free(p);
	return k;
}

// function 21
void qsort_orig(void* Arr, size_t n, size_t size, _Cmpfun* cmp) {
	char* S = (char*)Arr;
	size_t i, pivot;
	if (n > 1) {
		pivot = partition(S, n, size, cmp, 0);

		qsort_orig(S, pivot, size, cmp);
		qsort_orig(S + (pivot + 1) * size, n - pivot - 1, size, cmp);
	}
	return;
}

void insertion_sort(void* Arr, size_t n, size_t size, _Cmpfun* cmp) {

}

// function 22
void qsort_median_insert(void* Arr, size_t n, size_t size, _Cmpfun* cmp) {
	char* S;
	size_t pivot, a, b, c;
	size_t p, first, second, third, length, l, r;
	S = (char*)Arr;
	if (n < INS_SORT_SIZE) {
		insertion_sort(S, n, size, cmp);
		return;
	}
	// if array's size is small enough, function 22 will do insertion sort

	a = rand() % n;
	b = rand() % n;
	c = rand() % n;

	pivot = a > b ? a > c ? b > c ? b : c : a : a < c ? b < c ? b : c : a;
	//pivot is the middle one among those three.
}

void qsort_median_insert_iter(void* Arr, size_t n, size_t size, _Cmpfun *cmp)
{

}