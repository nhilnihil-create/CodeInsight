# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn(1e5 + 5);

int n, a[maxn];

bool Solve() {
	int d, i, cnt = 0;
	for (i = 1; i <= n; ++i) cnt += ~a[i] & 1;
	if (cnt & 1) return 1;
	for (i = 1; i <= n; ++i) if (a[i] == 1) return 0;
	if (n - cnt > 1) return 0;
	for (i = 1; i <= n; ++i) if (a[i] & 1) --a[i];
	d = a[1];
	for (i = 2; i <= n; ++i) d = __gcd(d, a[i]);
	for (i = 1; i <= n; ++i) a[i] /= d;
	return Solve() ^ 1;
}

int main() {
	int i, u, v;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
	Solve() ? puts("First") : puts("Second");
	return 0;
}