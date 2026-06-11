#include <cstdio>
#define N 200010
#define ll long long
#define mod 1000000007
using namespace std;

int h, w, a, b;
ll n[N] = {1}, m[N], ans;

inline ll pow(ll x, ll k) {
	ll ans = 1;
	while (k) {
		if (k & 1)
			ans = ans * x % mod;
		x = x * x % mod;
		k >>= 1;
	}
	return ans;
}

inline ll c(int a, int b) {
	return (n[a] * m[b] % mod) * m[a - b] % mod;
}

int main() {
	scanf("%d %d %d %d", &h, &w, &a, &b);
	for (int i = 1; i <= h + w - 2; ++i)
		n[i] = n[i - 1] * i % mod;
	m[h + w - 2] = pow(n[h + w - 2], mod - 2);
	for (int i = h + w - 3; i >= 0; --i)
		m[i] = m[i + 1] * (i + 1) % mod;
	for (int i = 1; i <= h - a; ++i)
		ans = (ans + c(b + i - 2, b - 1) * c(h - i + w - b - 1, h - i)) % mod;
	printf("%lld", ans);
	return 0;
}