#include <cstdio>
#include <algorithm>

const int MN = 100005;

int N, A[MN];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	int mx = *std::max_element(A + 1, A + N + 1);
	int mn = *std::min_element(A + 1, A + N + 1);
	if (mx == mn) {
		if (mx == N - 1) puts("Yes");
		else if (mx > N / 2) puts("No");
		else puts("Yes");
		return 0;
	}
	if (mx - mn >= 2) return puts("No"), 0;
	int cnt = 0;
	for (int i = 1; i <= N; ++i) if (A[i] == mn) ++cnt;
	puts(mx <= cnt || mx > cnt + (N - cnt) / 2 ? "No" : "Yes");
	return 0;
}