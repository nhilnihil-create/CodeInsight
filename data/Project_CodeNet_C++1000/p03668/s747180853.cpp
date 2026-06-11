#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,G[N];
vector < int > v[N];
void Dfs(int x,int p) {
	int G_=0;
	for (int i=0; i<v[x].size(); i++) 
		if (v[x][i]!=p) {
			Dfs(v[x][i],x);
			G_=(G_^(G[v[x][i]]+1));
		}
	
	G[x]=G_;
}
main () {
	cin>>n;
	
	for (int i=1; i<n; i++) {
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	Dfs(1,1);
	
	if (G[1]) cout<<"Alice\n";
		else cout<<"Bob\n";
}