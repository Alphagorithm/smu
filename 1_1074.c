#include <stdio.h>
#include <stdlib.h>

int z(int start, int col, int line, int len, int mul) {
	if (col < len / 2 && line >= len/2) { // 1사분면
		if (len == 2) {
			return start+1;
		}
		else {
			z(start + len*mul, col % (len / 2), line % (len / 2), len / 2, mul / 2);
		}
	}
	else if (col < len/2 && line < len/2) { // 2사분면
		if (len == 2) {
			return start;
		}
		else {
			z(start, col % (len / 2), line % (len / 2), len / 2, mul / 2);
		}
	}
	else if (col >= len/2 && line < len/2) { // 3사분면
		if (len == 2) {
			return start + 2;
		}
		else {
			z(start + len*mul * 2, col % (len / 2), line % (len / 2), len / 2, mul / 2);
		}
	}
	else if (col >= len/2 && line >= len/2) { // 4사분면
		if (len == 2) {
			return start + 3;
		}
		else {
			z(start + len*mul * 3, col % (len / 2), line % (len / 2), len / 2, mul / 2);
		}
	}
}

int main() {
	int num, i;
	int len;
	int mul;
	int col, line;

	while (scanf("%d %d %d", &num, &col, &line) != EOF) {
		len = 1;
		mul = 1;
		for (i = 0; i < num; i++)
			len *= 2;
		for (i = 0; i < num - 2; i++)
			mul *= 2;

		printf("%d\n", z(0, col, line, len, mul));
	}
	return 0;
}