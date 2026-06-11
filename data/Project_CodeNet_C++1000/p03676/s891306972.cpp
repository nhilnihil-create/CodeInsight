#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define pr pair<int, int>
#define x first
#define y second
using namespace std;

template<typename T>
void read(T& n){
	char ch; int sign = 1;
	while (!isdigit(ch = getchar())) if (ch == '-') sign = -1;
	n = ch - '0';
	while (isdigit(ch = getchar())) n = n * 10 + ch - '0';
	n *= sign;
}
typedef long long ll;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int N = 122222;
ll n, same, pos1, pos2;
ll a[N], vis[N], fac[N];

ll mut(ll a, ll b){
	ll y = 1, t = a;
	for (; b; b >>= 1, t = t * t % MOD)
		if (b & 1) y = y * t % MOD;
	return y;
}
ll C(ll n, ll m){
	if (n < m) return 0;
	return fac[n] * mut(fac[m], MOD - 2) % MOD * mut(fac[n-m], MOD - 2) % MOD;
}

int main(){
	read(n);
	rep(i, 1, n + 1) read(a[i]), vis[a[i]]++;
	rep(i, 1, n) if (vis[i] >= 2){same = i; break;}
	rep(i, 1, n + 1) if (a[i] == same) if (!pos1) pos1 = i; else pos2 = i;
	fac[0] = 1; rep(i, 1, n + 1) fac[i] = fac[i-1] * i % MOD;
	printf("%lld\n", n);
	rep(k, 2, n + 1){
		ll ret = (C(n - 1, k) + C(n - 1, k - 2) + C(n - 1, k - 1) * 2) % MOD;
		ret = (ret - C(n - pos2 + pos1, k - 1)) % MOD;
		printf("%lld\n", (ret + MOD) % MOD);
	}
	return 0;
}