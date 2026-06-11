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
ll keta(ll n) {
	ll res = 0;
	while (n >= 1) {
		res += n % 10; n /= 10;
	}
	return res;
}
ll nCk(ll n, ll k) {
	ll a = 1, b = 1;
	for (int h = n - k + 1; h <= n; h++) { a *= h; a %= mod; }
	for (int h = 1; h <= k; h++) { b *= h; b %= mod; }
	return a * modpow(b, mod - 2) % mod;
}
bool IsPrime(ll num) {
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false; // 偶数はあらかじめ除く
	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2) {
		if (num % i == 0) { // 素数ではない
			return false;
		}
	}
	// 素数である
	return true;
}

ll test[502][502];
signed main() {
	ll n, m, a, b, ans = 0; cin >> n >> m >> a >> b;
	ll ka = a * b - 2;
	for (int h = 1; h <= n; h++) {
		for (int i = 1; i <= m; i++) {
			if (h % a == 0 && i % b == 0) { 
				test[h][i] = 0 - (mod - 7); ans -= mod - 7;
			}
			else if ((h - 1) % a == 0 && (i - 1) % b == 0) {
				test[h][i] = mod - 8 - ka; ans += mod - 8 - ka;
			}
			else { test[h][i] = 1; ans += 1; }
		}
	}
	if (ans > 0) {
		cout << "Yes\n";
		for (int h = 1; h <= n; h++) {
			cout << test[h][1];
			for (int i = 2; i <= m; i++) {
				cout << ' ' << test[h][i];
			}
			cout << endl;
		}
	}
	else {
		cout << "No\n";
	}
	return 0;
}