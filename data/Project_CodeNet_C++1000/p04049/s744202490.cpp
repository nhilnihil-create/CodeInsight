#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
int n, k;
vector<vector<int>> dist;

void bfs(int i) {
	queue<pair<int, int>> q;
	q.emplace(i, 0);
	vector<int> vis(n);
	while (q.size()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (vis[x]) continue;
		dist[i][x] = y;
		dist[x][i] = y;
		vis[x] = 1;
		for (int node : a[x]) {
			q.emplace(node, y + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	a = vector<vector<int>>(n);
	dist = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y, x--, y--;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	int ans = 1e9, ind;
	for (int i = 0; i < n; i++) {
		bfs(i);
	}
	if (k % 2 == 0) {
		for (int i = 0; i < n; i++) {
			int res = 0;
			for (int j = 0; j < n; j++) {
				res += (dist[i][j] > k / 2);
			}
			ans = min(ans, res);
		}
		cout << ans << '\n';
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int node : a[i]) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				cnt += (min(dist[i][j], dist[node][j]) > k / 2);
			}
			ans = min(ans, cnt);
		}
	}
	cout << ans << '\n';
	return 0;
}



