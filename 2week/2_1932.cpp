#include <stdio.h>
#include <stdlib.h>

int sigma(int k) {
	int i, res = 0;
	for (i = 0; i <= k; i++)
		res += i;
	return res;
}

int getMax(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

void getRes(int * ptr, int * max, int i, int j) {
	int loop;
	if (i == 0)
		*(max + i) = *(ptr + i);
	else {
		for (loop = 0; loop < i + 1; loop++) {
			if (loop == 0) {
				*(max + j + loop) = *(max + j - i) + *(ptr + j + loop);
			}
			else if (loop == i) {
				*(max + j + loop) = *(max + j + loop - (i + 1)) + *(ptr + j + loop);
			}
			else {
				*(max + j + loop) = getMax(*(max + j + loop - i), *(max + j + loop - (i + 1))) + *(ptr + j + loop);
			}
		}
	}
}

int main(void) {
	int n, i, j, k, size = 0, res;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		size += i;
	}

	int * ptr = (int *)malloc(sizeof(int)* size);
	int * max = (int *)malloc(sizeof(int)* size);

	for (i = 0; i < size; i++) {
		scanf("%d", (ptr + i));
	}

	for (i = 0; i < n; i++) {
		for (j = sigma(i), k = 0; k < i + 1; k++) {
			getRes(ptr, max, i, j);
		}
	}

	j = sigma(n - 1);
	res = *(max + j);
	for (k = 1; k < n; k++)
		res = getMax(res, *(max + j + k));

	printf("%d\n", res);

	free(max);
	free(ptr);
	return 0;
}