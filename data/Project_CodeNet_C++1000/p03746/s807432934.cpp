#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100005];
bool vis[100005];
deque<int>dq;
void dfs1(int i){
	vis[i]=true;
	for(int j:adj[i]){
		if(!vis[j]){
			dq.push_front(j);
			dfs1(j);
			break;
		}
	}
}
void dfs2(int i){
	vis[i]=true;
	for(int j:adj[i]){
		if(!vis[j]){
			dq.push_back(j);
			dfs2(j);
			break;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dq.push_back(1);
	dfs1(1);
	dfs2(1);
	cout<<dq.size()<<"\n";
	for(int i:dq) cout<<i<<" ";
}