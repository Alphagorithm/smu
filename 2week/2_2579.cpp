#include <stdio.h>
#include <stdlib.h>

int getMax(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

void getRes1(int * ptr, int * max1, int * max2, int i) {
	if (i == 0) {
		*(max1 + i) = *(ptr + i);
	}
	else if (i == 1) {
		*(max1 + i) = *(max1 + i - 1) + *(ptr + i);
	}
	else {
		*(max1 + i) = *(max2 + i - 1) + *(ptr + i);
	}
}

void getRes2(int * ptr, int * max1, int * max2, int i) {
	if (i == 0) {
		*(max2 + i) = *(ptr + i);
	}
	else if (i == 1) {
		*(max2 + i) = *(ptr + i);
	}
	else {
		*(max2 + i) = getMax(*(max1 + i - 2), *(max2 + i - 2)) + *(ptr + i);
	}
}

int main(void) {
	int n, i, res;

	scanf("%d", &n);

	int* ptr = (int *)malloc(sizeof(int)* n);
	int* max1 = (int *)malloc(sizeof(int)* n);
	int* max2 = (int *)malloc(sizeof(int)* n);

	for (i = 0; i < n; i++)
		scanf("%d", (ptr + i));

	for (i = 0; i < n; i++) {
		getRes1(ptr, max1, max2, i);
		getRes2(ptr, max1, max2, i);
	}

	printf("%d\n", getMax(*(max1 + n - 1), *(max2 + n - 1)));

	free(max1);
	free(max2);
	free(ptr);
	return 0;
}