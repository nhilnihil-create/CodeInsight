#include<bits/stdc++.h>
using namespace std;

vector<int> e[100010];

int a[100010];
long long int dp[100010];
bool flag = true;
void dfs(int x,int p){
	if(e[x].size()==1)	dp[x]=a[x];
	else	dp[x]=a[x]*2;
	for(int it:e[x])
		if(it!=p){
			dfs(it,x);
			dp[x]-=dp[it];
			if(e[x].size()>1&&dp[it]>a[x])	flag = false;
		}
	if(dp[x]<0)	flag = false;
	if(e[x].size()>1&&dp[x]>a[x])	flag = false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1,u,v;i<n;i++)
		cin>>u>>v,e[u].emplace_back(v),e[v].emplace_back(u);
	dfs(1,0);
	if(dp[1]!=0)
		flag = false;
	if(flag)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}	
