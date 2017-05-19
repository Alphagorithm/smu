#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int number;
	int *arr;
	char *op;
	int index = 0;
	int i;
	int count = 0;
	int sp = 0;
	int plus = 0, minus = 0;
	scanf("%d", &number);
	arr = (int*)malloc(sizeof(int)*number);
	op = (char*)malloc(sizeof(int)*(number*2));

	for (i = 0; i < number; i++) {
		scanf("%d", arr+i);
	}

	for (i = 0; i < number; i++) {
		while (1) {
			if (arr[i] > sp) {
				op[index++] = '+';
				plus++;
				count++;
				sp++;
				sp = count;
			}
			else if (arr[i] < sp) {
				sp--;
			}
			else if (arr[i] == sp) {
				op[index++] = '-';
				minus++;
				sp--;
				while (1) {
					if (arr[sp - 1] == -1)
						sp--;
					else
						break;
				}
				break;
			}
		}
	}

	if (plus != minus)
		printf("NO\n");
	else {
		for (i = 0; i < number * 2; i++) {
			printf("%c\n", op[i]);
		}
	}


	return 0;
}