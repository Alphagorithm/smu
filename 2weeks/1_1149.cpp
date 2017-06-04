#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int DP[1000][3];
int RGB[1000][3];

int main() {
	int size;
	scanf("%d", &size);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &RGB[i][j]);
		}
	}

	DP[0][0] = RGB[0][0];
	DP[0][1] = RGB[0][1];
	DP[0][2] = RGB[0][2];

	for (int i = 1; i < size; i++) {
		DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + RGB[i][0];
		DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + RGB[i][1];
		DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + RGB[i][2];
	}

	cout << min(DP[size - 1][0], min(DP[size - 1][1], DP[size - 1][2])) << endl;
	return 0;
}