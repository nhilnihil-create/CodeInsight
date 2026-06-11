#include <stdio.h>

const int N = 1e5;

int n;
int a[N << 1 | 1], b[N << 1 | 1];

bool check(int t);

int main() {
	// freopen("contest.in", "r", stdin);
	// freopen("contest.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n - 1; ++i) scanf("%d", &a[i]);
	int l = 1, r = 2 * n - 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (!check(mid)) l = mid + 1;
		else r = mid;
	}
	printf("%d\n", l);
	return 0;
}

bool check(int t) {
	for (int i = 1; i <= 2 * n - 1; ++i) b[i] = a[i] <= t;
	for (int i = 0; i < n; ++i) {
		if (b[n - i] == b[n - i - 1]) return b[n - i];
		if (b[n + i] == b[n + i + 1]) return b[n + i];
	}
	return b[1];
}
