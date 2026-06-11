#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 2e5 + 5;

int n, m, k, par[N], a[N], b[N];
map <pii, int> mp;

int root(int v) {
	return ((par[v] == v)? v : par[v] = root(par[v]));
}

void merge(int v, int u) {
	v = root(v), u = root(u);
	if(v == u)
		return;
	par[v] = u;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k >> m;
	for (int i = 0; i < n; i++)
		par[i] = i;
	for (int i = 0; i < k; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		merge(v, u);
	}
	for (int i = 0; i < n; i++)
		a[i] = root(i);
	for (int i = 0; i < n; i++)
		par[i] = i;
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		merge(v, u);
	}
	for (int i = 0; i < n; i++) {
		b[i] = root(i);
		mp[make_pair(a[i], b[i])]++;
	}
	for (int i = 0; i < n; i++)
		cout << mp[make_pair(a[i], b[i])] << " ";
	cout << "\n";
}
