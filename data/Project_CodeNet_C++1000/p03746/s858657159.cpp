#include <iostream>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5;

vector <int> adj[N];
vector <int> ans1;
vector <int> ans2;
bool mark[N];
void ad1(int v) {
	mark[v] = true;
	ans1.push_back(v);
	for (auto u : adj[v]) {
		if (!mark[u]) {
			ad1(u);
			return ;
		}
	}
}
void ad2(int v) {
	mark[v] = true;
	ans2.push_back(v);
	for (auto u : adj[v]) {
		if (!mark[u]) {
			ad2(u);
			return ;
		}
	}
}
int main() {
	int n, m, u, v;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	mark[u] = mark[v] = true;
	ad1(u);
	ad2(v);
	cout << ans1.size() + ans2.size() << endl;
	for (int i = (int) ans1.size() - 1; i >= 0; i--) {
		cout << ans1[i] << " ";
	}
	for (int i = 0; i < ans2.size(); i++) {
		cout << ans2[i] << " ";
	}
	return 0;
}
