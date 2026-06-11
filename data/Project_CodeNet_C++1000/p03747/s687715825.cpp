#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

const int N = 1e5 + 10;
typedef long long ll;
ll n, L, T, a[N];

int main() {
	cin >> n >> L >> T;
	rep(i, 1, n) {
		int w; scanf("%lld%d", &a[i], &w);
		a[i] += (w == 1 ? T : -T);
	}
	int pos = 0;
	rep(i, 1, n) {
		pos += a[i] / L - (a[i] % L < 0);
		a[i] = (a[i] % L + L) % L;
	}
	sort(a + 1, a + n + 1);
	pos = (pos % n + n) % n + 1;
	rep(i, 1, n) {
		printf("%lld\n", a[pos]);
		pos = (pos == n ? 1 : pos + 1);
	}
	return 0;
}