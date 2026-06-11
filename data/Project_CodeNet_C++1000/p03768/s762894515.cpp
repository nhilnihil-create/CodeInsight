#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > g;
vector<vector<int> > v;
int main(){
	int n, m; cin>>n>>m;
	g.resize(n);
	for(int i = 0; i < m; i++){
		int u, v; cin>>u>>v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	v = vector<vector<int> > (n, vector<int>(11));
	int q; cin>>q;
	vector<int> ops(q+1);ops[0] = 0;
	for(int i = 1; i <= q; i++){
		int u, d, c; cin>>u>>d>>c; u--;
		ops[i] = c;
		v[u][d] = i;
	}
	
	for(int i = 10; i > 0; i--){
		for(int j = 0; j < n; j++){
			v[j][i-1] = max(v[j][i-1], v[j][i]);
			for(int adj: g[j]){
				v[adj][i-1] = max(v[adj][i-1], v[j][i]);
			}
		}
	}
	for(int i = 0; i < n; i++){
		cout<<(ops[v[i][0]])<<endl;
	}
}
