#include <stdio.h>
#include <stdlib.h>

int func() {
	int n, m, i, k=1, j;
	scanf("%d %d", &n, &m);

	int *ptr = (int *)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		scanf("%d", (ptr + i));
	}

	if (n == 1)
		return 1;

	while (1) {
		
		for (i = 1; i < n; i++) {
			if (*(ptr + i) > *(ptr + 0)) {
				int temp = *(ptr + 0);
				for (j = 0; j < n - 1; j++)
					*(ptr + j) = *(ptr + j + 1);
				*(ptr + n-  1) = temp;
				if (m == 0)
					m = n - 1;
				else
					m = m - 1;
				break;
			}
		}
		
		if ((i == n) && (m == 0)) {
			return k;
		}
		else if ((i == n) && (m != 0)) {
			for (j = 0; j < n - 1; j++)
				*(ptr + j) = *(ptr + j + 1);
			n = n - 1;
			m = m - 1;
			k++;
		}
	}

	free(ptr);

	return k;
}

int main(void) {
	int count, i=0;

	scanf("%d", &count);

	int *ptr = (int *)malloc(sizeof(int) * count);

	for (; i < count; i++) {
		*(ptr+i) = func();
	}

	for (i = 0; i < count; i++) {
		printf("%d\n", *(ptr + i));
	}

	free(ptr);

	return 0;
}