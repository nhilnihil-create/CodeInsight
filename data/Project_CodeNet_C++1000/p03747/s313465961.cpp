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
#define mod 998244353
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

int n, l, t, a[100010], w[100010];
vector<P> vec;

signed main() {
	cin >> n >> l >> t;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> w[i];
		if (w[i] == 1)vec.push_back(make_pair((a[i] + t) % l, 1));
		else vec.push_back(make_pair((a[i] + l - t % l) % l, 2));
	}
	sort(all(vec));
	int p = 0;
	if (w[0] == 1) {
		int cnt = 0;
		for (int i = 1; i < n; i++)if (w[i] == 2 && a[i] - a[0] < 2*t) cnt += 1 + (2*t - (a[i] - a[0])-1) / l;
		cnt %= n;
		int x = lower_bound(all(vec), make_pair((a[0] + t) % l, (int)1)) - vec.begin();
		p = x - cnt;
	}
	else {
		int cnt = 0;
		for (int i = 1; i < n; i++)if (w[i] == 1 && l - (a[i] - a[0]) < 2*t) cnt -= 1 + (2*t - (l - ((a[i] - a[0])))-1) / l;
		cnt %= n;
		cnt += n;
		cnt %= n;
		int x = lower_bound(all(vec), make_pair((a[0] + l - t % l) % l, (int)2)) - vec.begin();
		p = x - cnt;
	}
	for (int i = 0; i < n; i++) cout << vec[(i + p + n) % n].first << endl;
}