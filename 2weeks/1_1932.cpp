#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

int **arr;
int **last;
int num;
int ans;

int main() {
	scanf("%d", &num);
	arr = (int**)malloc(sizeof(int**)* num);
	last = (int**)malloc(sizeof(int**)* num);
	for (int i = 1; i <= num; i++) {
		last[i - 1] = (int*)malloc(sizeof(int*)* i);
	}

	for (int i = 1; i <= num; i++) {
		arr[i - 1] = (int*)malloc(sizeof(int*)* i);
		
		for (int j = 0; j < i; j++) {
			scanf("%d", &arr[i - 1][j]);
		}
	}

	for (int i = 0; i < num-1; i++) {
		last[num-2][i] = arr[num-2][i] + max(arr[num-1][i], arr[num-1][i+1]);
	}
	if (num >= 3) {
		for (int i = num - 3; i >= 0; i--) {
			for (int j = 0; j < i + 1; j++) {
				last[i][j] = arr[i][j] + max(last[i + 1][j], last[i + 1][j + 1]);
			}
		}
	}

	printf("%d\n", last[0][0]);
	return 0;
}