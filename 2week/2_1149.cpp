#include <stdio.h>

int min(int r, int g, int b) {
	int min;
	(r < g) ? min = r : min = g;
	(min < b) ? min = min : min = b;

	return min;
}

char set(int min, int  r, int  g, int  b) {
	if (min == r)
		return 'r';
	else if (min == g)
		return 'g';
	else if (min == b)
		return 'b';
}

int main(void) {
	int sum = 0, n, m, i, r, g, b;
	char color;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &r, &g, &b);
		if (sum == 0) {
			sum += min(r, g, b);
			color = set(min(r, g, b), r, g, b);
		}
		else {
			if (color == 'r') {
				sum += min(2147483647, g, b);
				color = set(min(2147483637, g, b), 2147483637, g, b);
			}
			else if (color == 'g') {
				sum += min(r, 2147483647, b);
				color = set(min(r, 2147483637, b), r, 2147483647, b);
			}
			else if (color == 'b') {
				sum += min(r, g, 2147483647);
				color = set(min(r, g, 2147483637), r, g, 2147483637);
			}
		}
	}

	printf("%d\n", sum);

	return 0;
}