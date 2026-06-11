#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
 
#define mp make_pair
#define pb push_back
 
 
typedef long long ll;
typedef long double ld;
 
using namespace std;
 
int n, m;
vector<int> eds[120000];
int was[120000];
int cl[120000];
int gl;
 
void dfs1(int v, int c) {
	cl[v] = c;
	was[v] = 1;
	for (int u: eds[v]) {
		if (!was[u]) {
			dfs1(u, c ^ 1);
		}
		else {
			if (cl[u] != (cl[v] ^ 1))
				gl = 1;
		}
	}
}
 
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	ll c0 = 0;
	ll c1 = 0;
	ll c2 = 0;
	for (int i = 0; i < n; ++i) {
		if (was[i])
			continue;
		if (eds[i].empty()) {
			++c2;
			continue;
		}
		gl = 0;
		dfs1(i, 0);
		if (gl)
			++c0;
		else
			++c1;
	}
	ll ans = 0;
	ans += c2 * n + (n - c2) * c2;
	ans += c1 * c1 * 2;
	ans += c0 * c0 + c0 * c1 + c1 * c0;
	cout << ans << "\n";
	return 0;
}