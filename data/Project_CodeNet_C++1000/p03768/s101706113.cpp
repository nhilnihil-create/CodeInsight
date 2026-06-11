#include<bits/stdc++.h>

using namespace std;
vector<int>adj[100005];
int col[100005];
int c[100005][11];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int v,d;
		cin>>v>>d>>col[i+1];
		v--;
		c[v][d]=i+1;
	} 
	for(int i=9;i>=0;i--){
		for(int v=0;v<n;v++){
			for(int u=0;u<adj[v].size();u++){
				c[adj[v][u]][i]=max(c[adj[v][u]][i],c[v][i+1]);
			}
		}
	}
	for(int v=0;v<n;v++){
		int res=0;
		for(int d=0;d<11;d++){
			res=max(res,c[v][d]);
		}
		cout<<col[res]<<endl;
	}
	return 0;
}