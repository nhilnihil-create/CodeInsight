#include <cstdio>
#include <algorithm>

const int MN = 100005;

int N, C, K, T[MN];

int main() {
	scanf("%d%d%d", &N, &C, &K);
	for (int i = 1; i <= N; ++i) scanf("%d", &T[i]);
	std::sort(T + 1, T + N + 1);
	int Ans = 0, lst = 0, cap = 0;
	for (int i = 1; i <= N; ++i) {
		if (cap == C || lst < T[i]) ++Ans, lst = T[i] + K, cap = 1;
		else ++cap;
	}
	printf("%d\n", Ans);
	return 0;
}