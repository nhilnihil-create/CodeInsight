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

int n, m;
int cnt[100010];
int cnt2[100010];
int cnt3[100010];
int ans;

signed main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		cnt[a%m]++;
		cnt2[a]++;
	}
	for (int i = 1; i <= 100000; i++)cnt3[i%m] += cnt2[i] - cnt2[i] % 2;
	for (int i = 1; i < (m + 1) / 2; i++)ans += min(cnt[i], cnt[m - i]);
	ans += cnt[0] / 2;
	if (m % 2 == 0)ans += cnt[m / 2] / 2;
	for (int i = 1; i < m; i++) {
		if (cnt[i] <= cnt[m - i])continue;
		ans += min(cnt[i] - cnt[m - i], cnt3[i]) / 2;
	}
	cout << ans << endl;
}