#include"bits/stdc++.h"
#include<cassert>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const int mod = 1000000007;
const int inf = 1ll << 61;
typedef pair<int, int> P;
typedef pair<int, P>PP;
vector<int>G[100006];
int color[100006];

int par[100006], siz[100006];
void init(int n) {
	rep(i, n) {
		par[i] = i; siz[i] = 1;
	}
}
int find(int x) {
	if (par[x] == x)return x;
	return par[x] = find(par[x]);
}
void unite(int x, int y) {
	x = find(x), y = find(y);
	if (x == y)return;
	if (siz[x] < siz[y])swap(x, y);
	par[y] = x;
	siz[x] += siz[y];
}

bool dfs(int now, int c) {
	color[now] = c;
	for(int e:G[now]){
		if (color[e] == c) {
			return false;
		}
		if (color[e] == 0 && !dfs(e, -c))return false;
	}
	return true;
}

signed main() {
	int n, m; cin >> n >> m;
	set<int>S,S1;
	init(n);
	rep(i, m) {
		int u, v; cin >> u >> v; u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
		S.insert(u); S.insert(v);
		unite(u, v);
	}
	rep(i, n)S1.insert(find(i));
	int t1 = 0, t2 = 0, t3 = n-S.size();
	for (auto itr = S1.begin(); itr != S1.end(); itr++) {
		int e = *itr;
		if (G[e].size()) {
			if (dfs(e, 1))t1++; else t2++;
		}
	}

	int ans = 2 * n*t3 - t3*t3;
	ans += t1*t1 * 2;
	ans += (2 * t1*t2 + t2*t2);
	cout << ans << endl;
}