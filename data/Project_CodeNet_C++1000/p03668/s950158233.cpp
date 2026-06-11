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
int kai(int x, int y, int m) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= m;
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

int comb(int x, int y, int m) {
	if (y > x)return 0;
	return kai(x, y, m) * mod_pow(kai(y, y, m), m - 2, m) % m;
}

int n;
vector<int> vec[100010];
int d[100010];

void dfs(int v, int p) {
	if ((v == 1 && (int)vec[v].size() == 1) || (1 < v && (int)vec[v].size() == 2)) {
		for (int i = 0; i < (int)vec[v].size(); i++) {
			if (vec[v][i] == p)continue;
			dfs(vec[v][i], v);
			d[v] = d[vec[v][i]] + 1;
		}
	}
	else {
		int k = 0;
		for (int i = 0; i < (int)vec[v].size(); i++) {
			if (vec[v][i] == p)continue;
			dfs(vec[v][i], v);
			k ^= d[vec[v][i]] + 1;
		}
		d[v] = k;
	}
}

signed main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(1, 0);
	if (d[1])cout << "Alice" << endl;
	else cout << "Bob" << endl;
}