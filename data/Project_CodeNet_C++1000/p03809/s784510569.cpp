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
#include <functional>
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

int n, a[100010];
vector<int> vec[100010];
bool bl = true;

ll dfs(int v, int p) {
	if ((int)vec[v].size() == 1)return a[v];
	ll cnt = 0, ma = 0;
	for (int i = 0; i < (int)vec[v].size(); i++) {
		if (vec[v][i] == p)continue;
		ll q = dfs(vec[v][i], v);
		cnt += q, ma = max(ma, q);
	}
	ll x = a[v] * 2 - cnt;
	if (x < 0 || a[v] < max(ma, x))bl = false;
	return x;
}

signed main() {
	std::random_device rnd;
	std::mt19937_64 mt(rnd());
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	if (n == 2) {
		if (a[1] != a[2])cout << "NO" << endl;
		else cout << "YES" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)if ((int)vec[i].size() > 1) {
		ll p = dfs(i, 0);
		if (!bl || p)cout << "NO" << endl;
		else cout << "YES" << endl;
		return 0;
	}
}