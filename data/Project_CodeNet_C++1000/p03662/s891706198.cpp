#include<iostream>
#include<vector>
using namespace std;

const int maxn = 1e5 + 5;

vector<int>vis(maxn), que(maxn), G[maxn];

int main() {
	int n; cin >> n;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		G[u].push_back(v); G[v].push_back(u);
	}
	int l = 1, r = 0;
	vis[l] = 1, vis[n] = 2;
	que[++r] = 1, que[++r] = n;
	while (l <= r) {
		int u = que[l++];
		for (auto v : G[u]) {
			if (!vis[v]) {
				vis[v] = vis[u];
				que[++r] = v;
			}
		}
	}
	int sumF = 0, sumS = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 1)sumF++;
		else sumS++;
	}
	cout << (sumF > sumS ? "Fennec" : "Snuke") << endl;

	return 0;
}