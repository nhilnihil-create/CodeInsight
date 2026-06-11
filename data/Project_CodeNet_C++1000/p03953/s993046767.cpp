#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 2e5 + 5;

ll n, a[N], x[N], m, f[N], ans[N];
bool mark[N];
ll k;

vector <int> adj[N], vec;

void dfs(int v) {
	vec.push_back(v);
	mark[v] = true;
	for (auto u : adj[v])
		if(!mark[u])
			dfs(u);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m >> k;
	for (int i = 0; i < n - 1; i++)
		x[i] = a[i + 1] - a[i], f[i] = i;
	for (int i = 0; i < m; i++) {
		int pos;
		cin >> pos;
		pos--;
		swap(f[pos], f[pos - 1]);
	}
	for (int i = 0; i < n - 1; i++)
		adj[i].push_back(f[i]);
	for (int v = 0; v < n - 1; v++)
		if(!mark[v]) {
			dfs(v);
			ll len = vec.size();
			for (int i = 0; i < len; i++)
				ans[vec[i]] = vec[(k + i) % len];
			vec.clear();
		}
	for (int i = 0; i < n - 1; i++) {
		cout << a[i] << "\n";
		a[i + 1] = a[i] + x[ans[i]];
	}
	cout << a[n - 1] << "\n";
}
