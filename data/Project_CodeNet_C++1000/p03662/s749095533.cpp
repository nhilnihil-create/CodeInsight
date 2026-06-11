#include<bits/stdc++.h>
using namespace std;
int n;
const int MAXN=1e5+5;
vector<int>g[MAXN];
int dist[2][MAXN],id;
void dfs(int idx,int par=-1){
	if(~par)dist[id][idx]=dist[id][par]+1;
	for(auto &to:g[idx])if(to!=par)dfs(to,idx);
}
int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	id=0;
	dfs(0);
	id=1;
	dfs(n-1);
	int ret=0;
	for(int i=0;i<n;i++){
		if(dist[0][i]<=dist[1][i])ret++;
	}
	if(2*ret>n)cout<<"Fennec";
	else cout<<"Snuke";
	return 0;
}