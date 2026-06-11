#include <bits/stdc++.h>

#define For(i, j, k) for (register int i = j; i <= k; ++ i)
#define Forr(i, j, k) for (register int i = j; i >= k; -- i)

using namespace std;

inline int read() {
	int x = 0, p = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') p = -1;
	for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	return x * p;
}

inline void File() {
	freopen("pyramid.in", "r", stdin);
	freopen("pyramid.out", "w", stdout);
}

const int N = 2e6 + 10;
int a[N], t[N], n, ans, tt;

inline bool check(int x) {
	For(i, 1, n) t[i] = a[i] <= x;

	for (register int i = 0, x, y; i < tt - 1; ++ i) {
		x = tt - i, y = x + 1;
		if (t[x] == 1 && t[y] == 1) return true;
		if (t[x] == 0 && t[y] == 0) return false;

		x = tt + i, y = tt + i + 1;
		if (t[x] == 1 && t[y] == 1) return true;
		if (t[x] == 0 && t[y] == 0) return false;
	}

	return t[1];
}

int main() {

	n = read(), tt = n, n = 2 * n - 1;
	For(i, 1, n) a[i] = read();

	for (int l = 1, r = n; l <= r; ) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}

	cout << ans << endl;
	return 0;
}
