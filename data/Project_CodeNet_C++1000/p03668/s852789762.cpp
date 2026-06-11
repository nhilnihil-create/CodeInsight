// Ala be zekrellah tatmaenolgholoob ...
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
#define MP make_pair
const int maxn = 1e5+9;
const ll mod = 1e9+7;

vector <int> g[maxn];
int grundy[maxn];

void dfs (int v, int parent = -1) {
	int num = 0;
	for (auto u : g[v]) {
		if (u == parent)
			continue;
		dfs(u, v);
		grundy[v] ^= grundy[u] + 1;
	}
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int v, u;
		cin >> v >> u;
		--v; --u;
		g[v].push_back(u);
		g[u].push_back(v);
		}
	dfs(0);
	if (grundy[0])
		cout << "Alice\n";
	else
		cout << "Bob\n";
}

