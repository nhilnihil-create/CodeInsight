#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5+25;
const ll mod = 1e9+7;

bool buf;
ll h, w, a, b;
ll n[4];
ll ch[4][maxn];

inline ll inv(ll x) {
	// x^(mod-2) % mod

	ll ret = 1, y = mod-2;
	while (y) {
		if (y&1)
			ret = (ret*x) % mod;
		x = (x*x) % mod;
		y >>= 1;
	}

	return ret;
}

void init() {
	ch[1][0] = 1;
	ch[2][0] = 1;

	for (int c = 1; c <= 2; c++) {
		for (int i = 1; i <= n[c]; i++) {
			ch[c][i] = ((ch[c][i-1] * (n[c]-i+1)) % mod) * inv(i);
			ch[c][i] %= mod;
			//cout << ch[c][i] << ' ';
		}
		//cout << endl;
	}
}

int main() {

	buf = scanf("%lld%lld%lld%lld", &h, &w, &a, &b);
	h--; w--;

	n[1] = h-a+b; n[2] = w+a-b;

	init();

	ll res = 0;
	for (int i = h-a-(w-b); i <= h-a; i++) 
		res = (res + ch[1][i]*ch[2][h-i]) % mod;

	printf("%lld\n", res);

	return 0;
}