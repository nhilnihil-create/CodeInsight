#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, ans, h[N], k;
vector<int> gr[N];
void dfs(int v, int par = 0) {
	for (auto u : gr[v]) {
		if (u != par) {
			dfs(u, v);
			h[v] = max(h[v], h[u] + 1);
		}
	}
	if (h[v] == k - 1 && par != 0)
		ans++, h[v] = -1;
//	cout << "v = " << v << " : " << h[v] << endl;
	return;
}
int main() {
	ios_base::sync_with_stdio (false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x--;
		if (i == 0) {
			if (x != 0)
				ans++;
		}
		else {
			gr[i].push_back(x);
			gr[x].push_back(i);
		}
	}
	dfs(0);
	cout << ans;
	return 0;
}
