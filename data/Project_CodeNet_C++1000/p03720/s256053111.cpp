#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

int g[55];

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		--u,--v;
		g[u]++;
		g[v]++;
	}
	for(int i=0;i<n;i++){
		cout<<g[i]<<'\n';
	}
	
	
}