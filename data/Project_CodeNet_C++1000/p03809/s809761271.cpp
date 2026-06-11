#include<bits/stdc++.h>
using namespace std;
long n,u,v,root;
long check[100005],a[100005];
vector<long> adj[100005];
bool dfs(int u){
	check[u]=1;
	if(adj[u].size()==1){
		return 1;
	}
	long sum=0, mx=-1;
	for(int v: adj[u]){
		if(check[v]==0){
			if(dfs(v)==0){
				return 0;
			}
			sum=sum+a[v];
			mx=max(mx,a[v]);
		}
	}
	if(a[u]<=sum && sum<=2*a[u] && mx<=a[u]){
		a[u]=2*a[u]-sum;
		if(u==root){
			if(a[u]==0){
				return 1;
			}else{
				return 0;
			}
		}else{
			return 1;
		}
	}else{
		return 0;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	root=1;
	for(int i=1;i<=n;i++){
		if(adj[i].size() > adj[root].size()){
			root=i;
		}
	}
	if(adj[root].size()==1){
		if(a[1]==a[2]){
			cout<<"YES";
		}else{
			cout<<"NO";
		}
	}else{
		if(dfs(root)==1){
			cout<<"YES";
		}else{
			cout<<"NO";
		}
	}
}