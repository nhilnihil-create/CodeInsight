#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector<int> v[100010];
vector<int> put;
int bio[100010];

void dfs(int x) {
	bio[x] = 1;
	put.push_back(x);
	
	for (int i = 0; i < v[x].size(); i ++) {
		int sus = v[x][i];
		if (bio[sus] == 0) {
			dfs(sus);
			break;
		}
	}
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < m; i ++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(a);
	reverse(put.begin(), put.end());
	for (int i = 0; i < v[a].size(); i ++) {
		if (bio[v[a][i]] == 0) {
			dfs(v[a][i]);
			break;
		}
	}
	
	cout << put.size() << endl;
	for (int i = 0; i < put.size(); i ++) {
		cout << put[i] << " ";
	}

	return 0;
}