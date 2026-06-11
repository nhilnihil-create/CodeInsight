#include <cstdio>

const int MN = 200005;

int N, M, A[MN];

inline bool check(int x) {
	int l = 1, r = M;
	for (int i = N; i > 1; --i)
		if ((A[i] >= x) == (A[i - 1] >= x)) { l = i; break; }
	for (int i = N; i < M; ++i)
		if ((A[i] >= x) == (A[i + 1] >= x)) { r = i; break; }
	if (l == 1 && r == M) return (A[N] >= x) ^ (~N & 1);
	return N - l <= r - N ? A[l] >= x : A[r] >= x;
}

int main() {
	scanf("%d", &N), M = 2 * N - 1;
	for (int i = 1; i <= M; ++i) scanf("%d", &A[i]);
	int l = 3, r = M - 1, mid, ans = 2;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}