#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

int n, L, T, a[MAXN];

int main() {
	long long cnt = 0LL;
	scanf("%d%d%d", &n, &L, &T);
	for (int i = 0; i < n; ++i) {
		int x, k;
		scanf("%d%d", &x, &k);
		x += k == 1 ? T : -T;
		cnt += x / L;
		x %= L;
		if (x < 0) x += L, --cnt;
		a[i] = x;
	}
	sort(a, a + n);
	cnt = (cnt % n + n) % n;
	for (int i = 0; i < n; ++i) printf("%d\n", a[(i + cnt) % n]);
}