#include<bits/stdc++.h>

using namespace std;
int a[100005],dp[100005];
vector<int>g[100005];
void dfs(int a){
	if(g[a].size()==0)return;
	for(int i=0;i<g[a].size();i++){
		dfs(g[a][i]);
	} 
	vector<int>top;
	for(int i=0;i<g[a].size();i++){
		top.push_back(dp[g[a][i]]);
	}
	sort(top.begin(),top.end());
	int mx=0,len=top.size();
	for(int i=0;i<top.size();i++){
		mx=max(mx,top[i]+len-i);
	}
	dp[a]=mx;
}
int main(){
	int n;
	cin>>n;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		g[a[i]].push_back(i);
	}
	dfs(1);
	cout<<dp[1]<<endl;
	return 0;
}