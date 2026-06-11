#include<bits/stdc++.h>
using namespace std;

#define eb emplace_back 
vector<int> e[100001];
bool vis[100001];
vector<int> ans,Ans;
void dfs(int x){
	vis[x]=true;
	ans.eb(x);
	for(int it:e[x])
		if(!vis[it]){
			dfs(it);
			break;
		}
}
void Dfs(int x){
	vis[x]=true;
	Ans.eb(x);
	for(int it:e[x])
		if(!vis[it]){
			Dfs(it);
			break;
		}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0,u,v;i<m;i++){
		cin>>u>>v;
		e[u].eb(v);
		e[v].eb(u);
	}
	dfs(1);
	Dfs(1);
	cout<<ans.size()+Ans.size()-1<<endl;
	for(int i=Ans.size()-1;i>=1;i--)
		cout<<Ans[i]<<' ';
	for(int it:ans)
		cout<<it<<' ';
	cout<<endl;
}

