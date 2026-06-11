#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	for (; ch > '9' || ch < '0'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch <= '9' && ch >= '0'; ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return x * f;
}

int n, a[200005], b[200005], ans;

inline bool check(int x) {
	for (int i = 1; i <= n; i++) b[i] = (a[i] >= x);
	for (int i = 1; i <= n / 2; i++) {
		if ((!b[n/2-i+1] && !b[n/2-i+2]) || (!b[n/2+i] && !b[n/2+i+1])) return 0;
		if ((b[n/2-i+1] && b[n/2-i+2]) || (b[n/2+i] && b[n/2+i+1])) return 1;
	}
	return b[1];
}

inline void solve() {
	int l = 1, r = n, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid; l = mid + 1;
		} else r = mid - 1;
	}
}

int main() {
	n = read() * 2 - 1;
	for (int i = 1; i <= n; i++) a[i] = read();
	solve();
	printf("%d\n", ans);
	return 0;
} 