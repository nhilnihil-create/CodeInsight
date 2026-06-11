#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 100000+10;
const int mod = 1e9 + 7;
int n;
vector<int> id;
int vis[M];
ll fact[M];

ll inv (ll x) {
	ll ret = 1;
	for (int i=mod-2; i; i>>=1) {
		if (i&1) ret = ret*x%mod;
		x = x*x%mod;
	}
	return ret;
}

ll C(int n,int k) {
	if (n<k) return 0;
	return fact[n] * inv(fact[n-k]) %mod * inv(fact[k]) %mod;
}

int main () {
	int len = -1;
	fact[0] = 1;
	scanf ("%d", &n);
	++n;
	for (int i=1, x; i<=n; ++i) {
		fact[i] = fact[i-1]*i%mod;
		scanf ("%d", &x);
		if (!vis[x]) {
			vis[x] = i;
		} else len = i - vis[x]+1;
	}
	printf ("%d\n", n-1);
	for (int k=2; k<=n; ++k) {
		ll ans = C(n-2, k) + C(n-2, k-2) + (2*C(n-2, k-1) - C(n-len, k-1));
		//ll ans = C(n, k) - (n-len, k-1);
		printf ("%lld\n", (ans+mod)%mod);
	}
	return 0;
}
