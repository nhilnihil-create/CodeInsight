#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100, inF = N;

int n, k, ans, out[N], dis[N];
bool mark[N];
vector<int> in[N];

void dfs(int v, bool change = false) {
	mark[v] = change;
	for (int u: in[v]) 
		if(mark[u] == false) {
			dis[u] = dis[v] + 1;
			dfs(u, change);
		}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k;
	cin >> out[0];
	ans += (out[0] != 1);
	
	for (int i = 1; i < n; i++) {
		cin >> out[i];
		in[--out[i]].push_back(i);
	}
	dfs(0);
	vector<int> vec(n);
	iota(vec.begin(), vec.end(), 0);
	sort(vec.begin(), vec.end(), [](int a, int b) {
		return dis[a] > dis[b];
	});
	for (int u: vec) {
		if(mark[u] || dis[u] <= k)
			continue;
		for (int i = 0; i < k - 1; i++)
			u = out[u];
		ans++;
		dfs(u, true);
	}
	cout << ans;
	return 0;
}