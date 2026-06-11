#include <cstdio>

int N, M, a, b;

int main() {
	scanf("%d%d%d%d", &N, &M, &a, &b);
	if (N % a == 0 && M % b == 0) return puts("No"), 0;
	puts("Yes");
	int v = 999999999 / (a * b - 1);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			printf("%d%c", i % a == 0 && j % b == 0 ? -(a * b - 1) * v - 1 : v, " \n"[j == M]);
	return 0;
}