#include <cstdio>

int N, x;

int main() {
	scanf("%d%d", &N, &x);
	if (x == 1 || x == N + N - 1) return puts("No"), 0;
	puts("Yes");
	if (N == 2) return puts("1\n2\n3\n"), 0;
	if (x == 2) {
		for (int i = 1; i <= N - 2; ++i) printf("%d\n", N - i + 1);
		printf("1\n2\n");
		for (int i = N + 1; i <= N + N - 1; ++i) printf("%d\n", i);
	} else if (x == N + N - 2) {
		for (int i = 1; i <= N - 2; ++i) printf("%d\n", N + i - 1);
		printf("%d\n%d\n", N + N - 1, N + N - 2);
		for (int i = N + 1; i <= N + N - 1; ++i) printf("%d\n", N + N - i);
	} else {
		int val = 1;
		for (int i = 1; i <= N - 3; ++i) {
			if (val == x - 2) val = x + 3;
			printf("%d\n", val++);
		}
		printf("%d\n%d\n%d\n%d\n%d\n", x + 2, x - 1, x, x + 1, x - 2);
		for (int i = N + 3; i <= N + N - 1; ++i) {
			if (val == x - 2) val = x + 3;
			printf("%d\n", val++);
		}
	}
	return 0;
}