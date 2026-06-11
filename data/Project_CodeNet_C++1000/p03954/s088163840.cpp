#include <bits/stdc++.h>

const int N = 200005;

int a[N], n;

bool check(int mid) {
	for (int i = 1; i < n; ++i) {
		if ((a[n - i] >= mid) == (a[n - i + 1] >= mid)) return a[n - i] >= mid;
		if ((a[n + i] >= mid) == (a[n + i - 1] >= mid)) return a[n + i] >= mid;
	}
	return a[1] >= mid;
}

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i < 2 * n; ++i)
		std::cin >> a[i];
	int L = 1, R = 2 * n - 1, ans;
	while (L <= R) {
		int mid = L + R >> 1;
		if (check(mid)) ans = mid, L = mid + 1;
		else R = mid - 1;
	}
	std::cout << ans << '\n';
	return 0;
}