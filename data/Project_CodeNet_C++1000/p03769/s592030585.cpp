#include <cstdio>
typedef long long ll;
const int N = 205;
ll n;
int a[55], len, cnt, length, lx[N], rx[N], nl, nr;
void solve(ll x) {
	while (x) a[++len] = x & 1, x >>= 1;
	nl = nr = 0;
	for (int i = len - 1; i; --i) {
		lx[++nl] = ++cnt;
		if (a[i]) rx[++nr] = ++cnt;
	}
		
	printf("%d\n", cnt << 1);
	for (int i = cnt; i; --i) printf("%d ", i);
	for (int i = nl; i; --i) printf("%d ", lx[i]);
	for (int i = 1; i <= nr; ++i) printf("%d ", rx[i]);
}
int main() {
	scanf("%lld", &n);
	solve(n + 1);
}