#include<bits/stdc++.h>
using namespace std;

int dist[100001];
int C[100001];
vector<int> e[100001];
void color(int x,int d,int c){
	if(d<=dist[x]||d<0)	return;
	dist[x]=d;
	if(!C[x])	C[x]=c;
	for(int it:e[x])
		color(it,d-1,c);
}
int V[100001],D[100001],CC[100001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,q;
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	cin>>q;
	memset(dist,-1,sizeof dist);
	for(int i=1;i<=q;i++)
		cin>>V[i]>>D[i]>>CC[i];
	for(int i=q;i>=1;i--)
		color(V[i],D[i],CC[i]);
	for(int i=1;i<=n;i++)
		cout<<C[i]<<'\n';
}

