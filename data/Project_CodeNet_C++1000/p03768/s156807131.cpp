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

int n, m, q, a[100010], b[100010], c[100010];
vector<int> vec[100010];
int d[100010][15];

void dfs(int v, int k, int x) {
	if (k < 0 || d[v][k])return;
	d[v][k] = x;
	for (int i = 0; i < (int)vec[v].size(); i++) dfs(vec[v][i], k - 1, x);
}

signed main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	cin >> q;
	for (int i = 1; i <= q; i++) cin >> a[i] >> b[i] >> c[i];
	for (int i = q; i >= 1; i--)dfs(a[i], b[i], i);
	for (int i = 1; i <= n; i++) {
		int ans = 0;
		for (int j = 0; j <= 10; j++)ans = max(ans, d[i][j]);
		cout << c[ans] << endl;
	}
}