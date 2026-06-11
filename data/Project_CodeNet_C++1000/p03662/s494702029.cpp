#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<numeric>
#include<queue>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> g(n, vector<int>());
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> fd(n,1000000);
	queue<int> que;
	que.push(0);
	fd[0] = 0;
	while (que.size()) {
		int k = que.front(); que.pop();
		for (auto e : g[k]) {
			if (fd[e] > fd[k] + 1) {
				fd[e] = fd[k] + 1;
				que.push(e);
			}
		}
	}
	int snk = 1;
	que.push(n-1);
	fd[n - 1] = 0;
	while (que.size()) {
		int k = que.front(); que.pop();
		for (auto e : g[k]) {
			if (fd[e] > fd[k] + 1) {
				fd[e] = fd[k] + 1;
				que.push(e);
				snk++;
			}
		}
	}
	cout << ((snk * 2 >= n) ? "Snuke" : "Fennec") << endl;
	return 0;
}