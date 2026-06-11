#include<bits/stdc++.h>

using namespace std;
vector<int>adj[100005];
int minDis[100005];
int color[100005],v[100005],d[100005],c[100005];
void dfs(int node,int Din,int CIN){
    if(Din<=minDis[node])return;
    minDis[node]=Din;
	if(color[node]==0)color[node]=CIN;
	for(int i=0;i<adj[node].size();i++){
		int to=adj[node][i];
		dfs(to,Din-1,CIN);
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)minDis[i]=-1;
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
		cin>>v[i]>>d[i]>>c[i];
	}
	for(int i=q;i>=0;i--)dfs(v[i]-1,d[i],c[i]);
	for(int i=0;i<n;i++)cout<<color[i]<<endl;
	return 0;
}