#include<bits/stdc++.h>
using namespace std;
int n, m, a, b;
deque<int> path;
int mem[100001];
	vector<vector<int> > v;
	
int dfs(int z, bool f) {
	mem[z] = 1;
	for(int i = 0; i < v[z].size(); i++) {
		if(mem[v[z][i]] == 0) {
			if(f) {
				path.push_back(v[z][i]);
			} else {
				path.push_front(v[z][i]);
			}
			return dfs(v[z][i], f);
		}
	}
	return 0;	
 }

int main() {
	cin >> n >> m;
	vector<int> vec;
	for(int i = 0; i < n; i++) {
		v.push_back(vec);
	}
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a - 1].push_back(b - 1);
		v[b - 1].push_back(a - 1);
	}
	mem[0] = 1;
	b = v[0][0];
	mem[b] = 1;
	path.push_back(0);
	path.push_front(b);
	for(int i = 0; i < v[0].size(); i++) {
		if(mem[v[0][i]] == 0) {
			mem[v[0][i]] = 1;	
			path.push_back(v[0][i]);
			dfs(v[0][i], 1);
			break;		
		}
	}
	for(int i = 0; i < v[b].size(); i++) {
		if(mem[v[b][i]] == 0) {
			mem[v[b][i]] = 1;
			path.push_front(v[b][i]);
			dfs(v[b][i], 0);
			break;
		}
	}
	cout << path.size() << endl;
	for(int i = 0; i < path.size(); i++) {
		cout << path[i] + 1<< " ";	
	}
}
