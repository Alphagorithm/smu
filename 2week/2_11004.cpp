#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	int* ptra = (int*)a;
	int* ptrb = (int*)b;

	return *ptra - *ptrb;
}

int main(void) {
	int n, k, i;

	scanf("%d %d", &n, &k);

	if (n > 5000000)
		return 0;

	int * ptr = (int *)malloc(sizeof(int)* n);

	for (i = 0; i < n; i++) {
		scanf("%d", (ptr + i));
	}

	qsort(ptr, n, sizeof(int), compare);

	printf("%d\n", *(ptr + (k - 1)));

	free(ptr);

	return 0;
}