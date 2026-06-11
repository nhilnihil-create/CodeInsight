#include<stdio.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include<stack>
#include <queue>
#include<map>
#include <set>
#include<math.h>
using namespace std;
#define int long long
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define loop(i,m,n) for(ll i=m;i<n;++i)
#define ggr getchar(); getchar();return 0;
#define pie 3.141592653589793238462643383279
#define elif else if
#define P pair<ll,ll>
const int inf = 1000000007;
int bin(int bina) {
	int ans = 0;
	for (int i = 0; bina > 0; i++)
	{
		ans = ans + (bina % 2) * pow(10, i);
		bina = bina / 2;
	}
	return ans;
}
bool prime(int n) {
	for (ll i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)return false;
	}
	return n != 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}
int kai(int x) {
	if (x == 0)return 1;
	return kai(x - 1) * x % inf;
}
int mod_pow(int x, int y, int mod) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % mod;
		}
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	return kai(x)* mod_pow(kai(x - y), inf - 2, inf) % inf * mod_pow(kai(y), inf - 2, inf) % inf;
}
struct union_find {
	int par[200010], size_[200010];
	void init(int x) {
		rep(i, x) { par[i] = i; size_[i] = 1; }
	}
	int find(int x) {
		if (par[x] == x)return x;
		return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y)return;
		if (size_[x] < size_[y]) {
			par[x] = y;
			size_[y] += size_[x];
		}
		else {
			par[y] = x;
			size_[x] += size_[y];
		}
	}
};
int n;
vector<int>v[100010];
int d[100010], da[100010];
bool b[100010], ba[100010];
void dfs(int a) {
	b[a] = true;
	rep(i, v[a].size()) {
		if (!b[v[a][i]]) {
			d[v[a][i]] = d[a] + 1;
			dfs(v[a][i]);
		}
	}
}
void dfs2(int a) {
	ba[a] = true;
	rep(i, v[a].size()) {
		if (!ba[v[a][i]]) {
			da[v[a][i]] = da[a] + 1;
			dfs2(v[a][i]);
		}
	}
}
signed main() {	
	cin >> n;
	rep(i, n - 1) {
		int a, c;
		cin >> a >> c;
		a--;
		c--;
		v[a].push_back(c);
		v[c].push_back(a);
	}
	dfs(0);
	dfs2(n - 1);
	int ans = 0, ans2 = 0;
	rep(i, n) {
		if (d[i] > da[i]) {
			ans2++;
		}
		else ans++;
	}
	if (ans > ans2) {
		cout << "Fennec" << endl;
	}
	else cout << "Snuke" << endl;
}