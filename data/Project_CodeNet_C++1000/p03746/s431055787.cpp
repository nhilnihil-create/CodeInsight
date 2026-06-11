#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector <int> neigh[100000];

bool passed[100000] = { 0 };

vector <int> path;

void dfs(int p) {
	passed[p] = 1;
	path.push_back(p);
	for(int i = 0; i < neigh[p].size(); i++) {
		if(!passed[neigh[p][i]]) {
			dfs(neigh[p][i]);
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		neigh[a - 1].push_back(b - 1);
		neigh[b - 1].push_back(a - 1);
	}

	dfs(0);

	vector <int> p1 = path;
	path = vector <int> ();

	dfs(0);

	cout << p1.size() + path.size() - 1 << '\n';

	for(int i = 0; i < path.size() - 1; i++) {
		cout << path[path.size() - 1 - i] + 1 << ' ';
	}

	for(int i = 0; i < p1.size(); i++) {
		cout << p1[i] + 1 << ' ';
	}

	return 0;
}
