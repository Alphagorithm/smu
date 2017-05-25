#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quick_sort(int* ptr, int i, int j) {

	int k;

	if (i >= j) return;

	int pivot = *(ptr + i);

	int p = i + 1, q = j;

	while (1) {
		while (*(ptr + p) <= pivot) { p++; }
		while (*(ptr + q) > pivot) { q--; }

		if (p>q) break;

		swap((ptr + p), (ptr + q));
	}

	swap((ptr + i), (ptr + q));

	quick_sort(ptr, i, q - 1);
	quick_sort(ptr, q + 1, j);

}

int funcQ(int * ptr, int i, int j, int k) {
	int c, d, len = j - i + 1;

	int * p = (int*)malloc(sizeof(int) * len);

	i--;
	j--;
	
	for (c = 0; c < len; c++) {
		*(p + c) = *(ptr + i + c);
	}
	
	quick_sort(p, 0, len-1);

	c = *(p + k - 1);

	free(p);

	return c;
}

int main(void) {
	int n, m, i, j, k;

	scanf("%d %d", &n, &m);

	int * ptr = (int *)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		scanf("%d", (ptr + i));

	while (m > 0) {
		scanf("%d %d %d", &i, &j, &k);
		printf("%d\n", funcQ(ptr, i, j, k));
		m--;
	}

	free(ptr);

	return 0;
}