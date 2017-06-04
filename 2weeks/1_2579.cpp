#include <cstdio>
#include <algorithm>
using namespace std;

int dp[300][2];
int cur[300];

int main() {
	int i, n;
	scanf("%d", &n);

	for (i = 0; i < n; i++) 
		scanf("%d", cur+i);

	dp[0][0] = dp[0][1] = cur[0];

	for (i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][1] + cur[i];
		dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + cur[i];
	}

	printf("%d\n", max(dp[n-1][0], dp[n-1][1]));
	return 0;
}