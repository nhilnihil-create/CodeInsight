#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


vector<vector<int> > edges;
vector<int> col;

LL ncc = 0;
LL nbcc = 0;

int ok;
int cnt = 0;

void dfs(int v, int c){
	if(col[v] == c) return;
	if(col[v] != 0){
		ok = 0;
		return;
	}
	cnt++;
	col[v] = c;
	for(int a : edges[v]){
		dfs(a, -c);
	}
}
LL n1 = 0;

int main(){
	LL n, m;
	cin >> n >> m;
	edges.resize(n);
	col.resize(n, 0);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(int i = 0; i < n; i++){
		if(col[i] == 0){
			ok = 1;
			cnt = 0;
			dfs(i, 1);
			if(cnt == 1){
				n1++;
			} else {
				ncc++;
				if(ok) nbcc++;
			}
		}
	}
	cout << n * n - (n - n1) * (n - n1) + nbcc * nbcc + ncc * ncc << '\n';
}