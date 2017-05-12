#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct package {
	int num;
	int index;
}Pack;

int compare(const void* pack1, const void* pack2) {
	const Pack *a = (const Pack*)pack1;
	const Pack *b = (const Pack*)pack2;

	if (a->num > b->num)
		return 1;
	else if (a->num < b->num)
		return -1;
	else
		return 0;
}

int main() {
	int num1, num2;
	int i, j, k;
	int count;
	int temp[3];
	Pack *arr;

	scanf("%d %d", &num1, &num2);
	arr = (Pack*)malloc(sizeof(Pack)*num1);
	

	for (i = 0; i < num1; i++) {
		scanf("%d", &arr[i].num);
		arr[i].index = i + 1;
	}
	qsort(arr, num1, sizeof(Pack), compare);

	for (i = 0; i < num2; i++) {
		for (k = 0; k < 3; k++) {
			scanf("%d", temp + k);
		}
		count = 1;
		for (j = 0; j < num1; j++) {
			if (arr[j].index >= temp[0] && arr[j].index <= temp[1]) {
				if (count == temp[2]) {
					printf("%d\n", arr[j].num);
					break;
				}
				count++;
			}
		}
	}

	free(arr);
	return 0;
}