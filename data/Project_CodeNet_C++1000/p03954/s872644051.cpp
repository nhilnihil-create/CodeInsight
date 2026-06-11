#include <cstdio>

const int MaxN = 200005;

int n, arr[MaxN];

bool check(int x) {
	auto get = [x](int pos) { return arr[pos] > x; };
	int l = 0;
	while (l + 1 < n && get(n - l - 1) != get(n - l)) ++l;
	int r = 0;
	while (r + 1 < n && get(n + r + 1) != get(n + r)) ++r;
	return l < r ? get(n - l) : get(n + r);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < 2 * n; ++i) scanf("%d", arr + i);
	int l = 1, r = 2 * n - 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	printf("%d\n", l);
	return 0;
}