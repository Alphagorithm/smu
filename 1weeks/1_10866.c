#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int arr[10000];
	int num;
	int i, j, k;
	int val;
	int size = 0;
	char enter[11];
	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%s", enter);
		if (strcmp("push_front", enter) == 0) {
			scanf("%d", &val);
			for (j = size; j >= 1; j--) {
				arr[j] = arr[j-1];
			}
			arr[0] = val;
			size++;
		}
		else if (strcmp("push_back", enter) == 0) {
			scanf("%d", &val);
			arr[size] = val;
			size++;
		}
		else if (strcmp("pop_front", enter) == 0) {
			if (size == 0)
				printf("-1\n");
			else {
				printf("%d\n", arr[0]);
				size--;
				for (j = 0; j < size; j++) {
					arr[j] = arr[j + 1];
				}
			}
		}
		else if (strcmp("pop_back", enter) == 0) {
			if (size == 0)
				printf("-1\n");
			else {
				size--;
				printf("%d\n", arr[size]);
			}
		}
		else if (strcmp("size", enter) == 0) {
			printf("%d\n", size);
		}
		else if (strcmp("empty", enter) == 0) {
			if (size == 0)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strcmp("front", enter) == 0) {
			if (size == 0)
				printf("-1\n");
			else
				printf("%d\n", arr[0]);
		}
		else if (strcmp("back", enter) == 0) {
			if (size == 0)
				printf("-1\n");
			else
				printf("%d\n", arr[size-1]);
		}
	}

	return 0;
}