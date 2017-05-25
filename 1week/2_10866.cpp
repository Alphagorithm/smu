#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

int dequeue[MAX];
int size = 0;

int empty() {
	if (size == 0)
		return 1;
	else
		return 0;
}

void push_front(int k) {
	int i;
	if (size == 0) {
		dequeue[0] = k;
	}
	else {
		for (i = size; i > 0; i--)
			dequeue[i] = dequeue[i - 1];
		dequeue[0] = k;
	}
	size++;
}

void push_back(int k) {
	if (size == 0) {
		dequeue[0] = k;
	}
	else {
		dequeue[size] = k;
	}
	size++;
}

int pop_front() {
	int i, k;
	if (size == 0)
		k = -1;
	else {
		k = dequeue[0];
		for (i = 0; i < size; i++)
			dequeue[i] = dequeue[i + 1];
		size--;
	}

	return k;
}

int pop_back() {
	int k;

	if (size == 0)
		k = -1;
	else {
		k = dequeue[size - 1];
		size--;
	}

	return k;
}

int main(void) {
	int n, k = 0;
	char str[100] = "";

	scanf("%d", &n);
	
	while (n > 0) {
		scanf("%s", str);
		
		if (!strcmp(str, "size")) {
			printf("%d\n", size);
		} 
		else if (!strcmp(str, "empty")) {
			printf("%d\n", empty());
		}
		else if (!strcmp(str, "front")) {
			printf("%d\n", dequeue[0]);
		}
		else if (!strcmp(str, "back")) {
			printf("%d\n", dequeue[size-1]);
		}
		else if (!strcmp(str, "push_front")) {
			scanf("%d", &k);
			push_front(k);
		}
		else if (!strcmp(str, "push_back")) {
			scanf("%d", &k);
			push_back(k);
		}
		else if (!strcmp(str, "pop_front")) {
			printf("%d\n", pop_front());
		}
		else if (!strcmp(str, "pop_back")) {
			printf("%d\n", pop_back());
		}

		n--;
	}

	return 0;
}