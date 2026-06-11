#include <bits/stdc++.h>
using namespace std;

int n, x, y, g[100005];
vector<int> v[100005];

void sgd(int dg, int op) {
	for(int i = 0; i < v[dg].size(); ++i) {
		if(v[dg][i] != op) {
			sgd(v[dg][i], dg);
			g[dg] ^= g[v[dg][i]] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; ++i) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	sgd(1, 0);
	if(g[1]) cout << "Alice" << endl;
	else cout << "Bob" << endl;
	return 0;
}