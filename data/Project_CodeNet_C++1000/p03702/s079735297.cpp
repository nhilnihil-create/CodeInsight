#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<17, mod = 1e9 + 7, i2 = (mod+1)/2;
ll n, a, b, h[maxn];
bool can(ll x) {
	ll t = 0;
	for(int i = 0; i < n; i++) t += (max(0ll, h[i] - x*b)+a-1)/a;
	return t <= x;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> a >> b;
	a -= b;
	for(int i = 0; i < n; i++) cin >> h[i];
	int ans = 0;
	for(ll i = 1ll<<50; i>>=1;)
		if(!can(ans+i)) ans += i;
	cout << ans+1;
	return 0;
}
