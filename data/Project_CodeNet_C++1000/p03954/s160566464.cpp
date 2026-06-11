#include <bits/stdc++.h>

#define MAXN 200005

using namespace std;

int n, a[MAXN], b[MAXN], maxi;

int read() {
	char c = getchar();
	int x = 0;
	while (!isdigit(c))
		c = getchar();
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x;
}

bool check(int w) {
	for (int i = 1; i <= 2 * n - 1; ++i) 
		b[i] = a[i] >= w;
	for (int i = 0; i < n - 1; ++i)
		if ((b[n - i] && b[n - i - 1]) || (b[n + i] && b[n + i + 1]))
			return true;
		else if ((!b[n - i] && !b[n - i - 1]) || (!b[n + i] && !b[n + i + 1]))
			return false;
	return b[1];
}

int solve() {
	int l = 1, r = 2 * n - 1, res = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			res = mid;
			l = mid + 1;
		}
		else 
			r = mid - 1;
	}
	return res;
}

int main() {
	n = read();
	for (int i = 1; i <= 2 * n - 1; ++i) 
		maxi = max(maxi, a[i] = read());
	int ans = solve();
	printf("%d\n", ans);
}