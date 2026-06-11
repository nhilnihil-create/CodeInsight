#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
vector<int>to[200005];
int main() {
	int n, m;
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--; b--;
		to[a].push_back(b);
		to[b].push_back(a);
	}
	queue<int>que;
	vector<int>dist(n, inf);
	dist[0] = 0;
	que.push(0);
	while (!que.empty()) {
		int v = que.front();
		que.pop();
		for (int id : to[v]) {
			if (dist[id] != inf)continue;
			dist[id] = dist[v] + 1;
			que.push(id);
		}
	}
	if (dist[n - 1] == 2) {
		cout << "POSSIBLE" << endl;
	}
	else {
		cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}