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
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define int long long
#define P pair<int,int>
#define all(vec) vec.begin(),vec.end()

int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= mod;
	}
	return res;
}
int mod_pow(int x, int y, int m) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}

int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y) * mod_pow(kai(y, y), mod - 2, mod) % mod;
}

int s = 1;
vector<int> dat, lazy;

void init(int n_) {
	while (s < n_)s *= 2;
	dat.resize(2 * s - 1, 0);
	lazy.resize(2 * s - 1, 0);
}

void eval(int k, int l, int r) {
	if (lazy[k]) {
		dat[k] += lazy[k];
		if (r - l > 1) {
			lazy[2 * k + 1] += lazy[k] / 2;
			lazy[2 * k + 2] += lazy[k] / 2;
		}
		lazy[k] = 0;
	}
}

void add(int a, int b, int x, int k = 0, int l = 0, int r = s) {
	eval(k, l, r);
	if (r <= a || b <= l)return;
	if (a <= l && r <= b) {
		lazy[k] += (r - l)*x;
		eval(k, l, r);
		return;
	}
	add(a, b, x, 2 * k + 1, l, (l + r) / 2);
	add(a, b, x, 2 * k + 2, (l + r) / 2, r);
	dat[k] = dat[2 * k + 1] + dat[2 * k + 2];
}

int query(int a, int b, int k = 0, int l = 0, int r = s) {
	if (r <= a || b <= l)return 0;
	eval(k, l, r);
	if (a <= l && r <= b)return dat[k];
	int vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
	int vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
	return vl + vr;
}

int n, m, a[100010];
int cnt;
int ans = 10000000000;

signed main() {
	cin >> n >> m;
	init(m + 2);
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 1; i < n; i++) {
		if (a[i - 1] <= a[i])cnt += a[i] - a[i - 1];
		else cnt += a[i];
	}
	ans = cnt;
	for (int i = 1; i < n; i++) {
		if (a[i - 1] <= a[i]) {
			if (a[i] == a[i - 1] + 1)continue;
			add(a[i - 1] + 2, a[i] + 1, -1);
			add(a[i] + 1, a[i] + 2, a[i] - a[i - 1] - 1);
		}
		else {
			if (a[i - 1] == m && a[i] == 1)continue;
			if (a[i - 1] < m - 1)add(a[i - 1] + 2, m + 1, -1);
			if (a[i - 1] == m)add(2, a[i] + 1, -1);
			else add(1, a[i] + 1, -1);
			add(a[i] + 1, a[i] + 2, m + a[i] - a[i - 1] - 1);
		}
	}
	for (int i = 2; i <= m; i++) {
		cnt += query(i, i + 1);
		ans = min(ans, cnt);
	}
	cout << ans << endl;
}
