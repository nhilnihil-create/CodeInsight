#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#include<functional>
//#include<bits/stdc++.h>
#define rep(i, x) for(ll i = 0; i < x; i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
const ld pi = 3.141592653589793238;
//printf("%.10f\n", n);

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	if (a % b == 0)return b;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
ll modpow(ll x, ll y) {
	ll res = 1;
	while (y) {
		if (y % 2) { res *= x; res %= mod; }
		x = x * x % mod; y /= 2;
	}
	return res;
}

ll a[123], b[123], c[123], d[123];
signed main() {
	ll n, m, ans = 1; cin >> n >> m;
	rep(i, n) {
		cin >> a[i] >> b[i];
	}
	rep(i, m) {
		cin >> c[i] >> d[i];
	}
	rep(i, n) {
		ll cnt = INF;
		rep(j, m) {
			if (cnt > abs(a[i] - c[j]) + abs(b[i] - d[j])) {
				cnt = abs(a[i] - c[j]) + abs(b[i] - d[j]); ans = j;
			}
		}
		cout << ans + 1 << endl;
	}
	return 0;
}