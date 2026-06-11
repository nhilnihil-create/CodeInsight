#include <bits/stdc++.h>
#define ls (o << 1)
#define rs (o << 1 | 1)
#define mid ((L + R + 1) >> 1)
using namespace std;
const int MAXN = 100050;
const int mod = 998244353;
typedef long long LL;
int n;
int a[MAXN], h[MAXN];
LL ans[MAXN];
bool cmp(const int &o, const int &p) { return a[o] > a[p]; }
int main() {
#ifdef TEST
	freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]), h[i] = i;
	sort(h, h + n, cmp);
	int now = h[0];
	for (int i = 1; i < n; ++i) {
		ans[now] += 1LL * i * (a[h[i - 1]] - a[h[i]]);
		if (now > h[i]) now = h[i];
	}
	ans[now] += 1LL * n * a[h[n - 1]];
	for (int i = 0; i < n; ++i) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}