#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int k, l, n, c, comp[N], nb[N];
vector <int> adjk[N], adjl[N], ver;
bool mark1[N], mark2[N];
map <int, int> m;

void input();
void dfs1(int);
void dfs2(int);

int main() {
	
	input();
	for (int i = 0; i < n; i++) {
		if (!mark1[i]) {
			dfs1(i);
			c++;
		}	
	}
	 	
	for (int i = 0; i < n; i++) {
		if (!mark2[i]) {
			ver.clear();
			m.clear();
			dfs2(i);
			for (auto x: ver) {
				nb[x] = m[comp[x]];
			}
		}	
	}
	
//	for (int i = 0; i < c; i++) {
//		cout << comps[i] << ' '; 
//		comps[i] = (comps[i] * (comps[i] - 1)) / 2;
//	}
	
	for (int i = 0; i < n; i++) {
//		cout << i << ' ' << comp[i] << ':' << comp2[i] << '\n';
		cout << nb[i] << ' ';
	}
	
}

void input() {
	
	cin >> n >> k >> l;
	
	for (int i = 0; i < k; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adjk[u].push_back(v);
		adjk[v].push_back(u);
	}
	
	for (int i = 0; i < l; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adjl[u].push_back(v);
		adjl[v].push_back(u);
	}		
	
}

void dfs1(int u) {
	
	mark1[u] = true;
	comp[u] = c;
	
	for (auto v: adjk[u]) {
		if (!mark1[v])
			dfs1(v);
	}
	
}

void dfs2(int u) {
	
	mark2[u] = true;
	m[comp[u]]++;
	ver.push_back(u);
	
	for (auto v: adjl[u]) {
		if (!mark2[v])
			dfs2(v);
	}
	
}