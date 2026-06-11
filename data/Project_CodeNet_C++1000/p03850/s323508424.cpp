#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<17, mod = 1e9 + 7;
ll n, _a[maxn], a[maxn], mn[maxn], mx[maxn];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	char t;
	for(int r = 0, i = 0; i < n; i++) {
		if(i) cin >> t;
		else t = '+';
		cin >> a[i];
		if(t == '-') a[i] = -a[i];
		_a[i] = a[i];
		if(r) a[i] = -a[i];
		if(t == '-') r ^= 1;
	}
	//for(int i = 0; i < n; i++) cout << a[i] << " "; cout << '\n';
	ll ss = 0, _mn = 0, _mx = 0;
	for(int i = n; i--;) {
		ss += a[i];
		mn[i] = min(mn[i+1] + a[i], _a[i] < 0 ? ss + _mn : (1ll<<60));
		mx[i] = max(mx[i+1] + a[i], _a[i] < 0 ? ss + _mx : -(1ll<<60));
		_mn = min(_mn, -ss-mx[i]);
		_mx = max(_mx, -ss-mn[i]);
		//cout << i << " " << mn[i] << " " << mx[i] << '\n';
	}
	cout << mx[0];
	return 0;
}
