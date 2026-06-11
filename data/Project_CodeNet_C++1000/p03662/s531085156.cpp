#include<bits/stdc++.h>
using namespace std;
const int inf=1<<30;
int dist[100010],dist2[100010];
vector<int> g[100010];
void dfs(int now,int par,int d){
	dist[now]=d;
	for(int i=0;i<g[now].size();i++){
		if(g[now][i]!=par){
			dfs(g[now][i],now,d+1);
		}
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a); 
	}
	dfs(n,0,0);
	for(int i=0;i<100010;i++)dist2[i]=dist[i];
	dfs(1,0,0);
	int fec=0,snk=0;
	for(int i=1;i<=n;i++){
		if(dist2[i]>=dist[i])fec++;
		else snk++;
	}
	if(fec>snk)cout<<"Fennec"<<endl;
	else cout<<"Snuke"<<endl;
	return 0;
}