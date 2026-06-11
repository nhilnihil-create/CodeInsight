#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n, m, a[MAXN];
long long ans, mx, value[MAXN];
int func(int x, int y) {
	if (y > x) return y - x;
	else return y + m - x;
}
void modify(int l, int r, int v) {
	value[l] += v;
	value[r + 1] -= v;
}
void Debug() {
	for (int i = 2; i <= m; i++)
		value[i] += value[i - 1];
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		if (i != 1) ans += func(a[i - 1], a[i]);
	}
	for (int i = 2; i <= n; i++) {
		int x = a[i - 1], y = a[i], d = func(x, y);
		if (x < y) {
			modify(x + 2, y, 1);
			modify(y + 1, y + 1, -(d - 1));
		} else {
			modify(x + 2, m, 1);
			if (x != m) {
				modify(1, 1, m - x - 1);
				modify(1, y, 1);
			} else modify(2, y, 1);
			modify(y + 1, y + 1, -(d - 1));
		}
	}
	for (int i = 2; i <= m; i++)
		value[i] += value[i - 1];
	for (int i = 2; i <= m; i++)
		value[i] += value[i - 1];
	for (int i = 1; i <= m; i++)
		mx = max(mx, value[i]);
	cout << ans - mx << endl;
	return 0;
}