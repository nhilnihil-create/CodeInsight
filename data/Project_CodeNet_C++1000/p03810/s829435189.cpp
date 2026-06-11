#include <cstdio>
#include <algorithm>

const int MN = 100005;

int N, A[MN];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	if (N == 1) return puts("Second"), 0;
	for (int o = 0; ; o ^= 1) {
		int Cnt = 0;
		for (int i = 1; i <= N; ++i) if (A[i] & 1) ++Cnt;
		if ((N - Cnt) & 1) return puts(o ? "Second" : "First"), 0;
		if (Cnt > 1) return puts(o ? "First" : "Second"), 0;
		for (int i = 1; i <= N; ++i) if (A[i] == 1) return puts(o ? "First" : "Second"), 0;
		int x = 0;
		for (int i = 1; i <= N; ++i) x = std::__gcd(x, A[i] & -2);
		for (int i = 1; i <= N; ++i) A[i] /= x;
	}
	return 0;
}