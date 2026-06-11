#include <cstdio>

const int MN = 505, MNN = 250005;

int N, B[MNN], f[MN], g[MN];

int main() {
	scanf("%d", &N);
	for (int i = 1, x; i <= N; ++i) scanf("%d", &x), B[x] = i;
	for (int i = 1, S = 0; i <= N * N; ++i) S += !B[i], B[i] ? g[B[i]] = S : 0;
	for (int i = 1; i <= N * N; ++i) {
		if (!B[i]) {
			int o = 0;
			for (int j = 1; j <= N; ++j) if (f[j] < j - 1)
				o = o ? g[o] - o + f[o] < g[j] - j + f[j] ? o : j : j;
			if (!o) for (int j = 1; j <= N; ++j) if (j <= f[j] && f[j] < N) { o = j; break; }
			if (!o) return puts("No"), 0;
			B[i] = o, ++f[o];
		} else if (++f[B[i]] != B[i]) return puts("No"), 0;
	}
	puts("Yes");
	for (int i = 1; i <= N * N; ++i) printf("%d%c", B[i], " \n"[i == N * N]);
	return 0;
}