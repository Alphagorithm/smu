#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int a[4000];
int b[4000];
int c[4000];
int d[4000];
int AB[16000000];
int CD[16000000];

int main() {
	int num;
	int i, j, k;
	long long total = 0;

	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	}

	k = 0;
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			AB[k] = a[i] + b[j];
			CD[k] = c[i] + d[j];
			k++;
		}
	}

	sort(AB, AB + num*num);
	sort(CD, CD + num*num);

	for (i = 0; i < num*num; i++) {
		int dest = AB[i] * (-1);
		auto lower = lower_bound(CD, CD + num*num, dest) - CD;
		auto upper = upper_bound(CD, CD + num*num, dest) - CD;

		for (auto it = lower; it != upper; it++) {
			total++;
		}
	}

	printf("%lld\n", total);
	return 0;
}