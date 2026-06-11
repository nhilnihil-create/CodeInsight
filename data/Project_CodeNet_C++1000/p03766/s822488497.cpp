#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <set>
#include <stdio.h>
#include <ctype.h>
#include <random>
#include <string.h>
#include <cmath>
#include <unordered_map>
#include <cstdio>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long ll;

ll gcd(ll x, ll y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
ll lcm(ll x, ll y) {
	return x / gcd(x, y)*y;
}
ll kai(ll x, ll y, ll m) {
	ll res = 1;
	for (ll i = x - y + 1; i <= x; i++) {
		res *= i; res %= m;
	}
	return res;
}
ll mod_pow(ll x, ll y, ll m) {
	ll res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}

ll comb(ll x, ll y, ll m) {
	if (y > x)return 0;
	return kai(x, y, m) * mod_pow(kai(y, y, m), m - 2, m) % m;
}

const ll mod = 1000000007;

ll n;
ll d[1000010], cum[1000010];
ll ans;

signed main() {
	cin >> n;
	d[1] = 1;
	cum[1] = 1;
	ans = (n - 1)*(n - 1) % mod;
	for (int i = 2; i <= n; i++) {
		d[i] = (cum[i - 1] - d[i - 2] + mod) % mod;
		cum[i] = (cum[i - 1] + d[i]) % mod;
		if (i == n)break;
		ans = (ans + d[i] * (n - 1) % mod*(n - 1) % mod) % mod;
		ans = (ans + d[i] * min(n - 1, i + 1LL) % mod) % mod;
	}
	ans = (ans + d[n] * n) % mod;
	if (n == 2)ans++;
	else if (3 <= n)ans = (ans + 2) % mod;
	cout << ans << endl;
}