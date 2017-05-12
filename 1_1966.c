#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct pack {
	int num;
	int index;
}Pack;

int main() {
	int number;
	int num1, num2;
	int i, j , k, a;
	Pack arr[100];
	Pack temper;
	Pack key;
	int check;
	int count;

	scanf("%d", &number);
	for (i = 0; i < number; i++) {
		count = 0;
		scanf("%d %d", &num1, &num2);
		for (j = 0; j < num1; j++) {
			scanf("%d", &arr[j].num);
			arr[j].index = j;
		}

		while (1) {
			check = 0;
			key = arr[0];
			for (k = 1; k < num1; k++) {
				if (key.num < arr[k].num) {
					temper = key;
					for (a = 0; a < num1-1; a++) {
						arr[a] = arr[a + 1];
					}
					arr[num1-1] = key;
					check = 1;
					break;
				}
			}
			if (check == 0) {
				count++;
				arr[0].num = -1;
			}
			if (check == 0 && key.index == num2) {
				printf("%d\n", count);
				break;
			}
		}
	}

	return 0;
}