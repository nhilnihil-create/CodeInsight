#include <stdio.h>

int N;

int main(void) {
	scanf("%d", &N);

	int i = 1;
	while ((1 + i)*i < N * 2) {
		i++;
	}
	while (N > 0) {
		if (N - i >= 0) {
			printf("%d\n", i);
			N -= i;
		}
		i--;
	}

	return 0;
}