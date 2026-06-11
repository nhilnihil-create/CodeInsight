#include<bits/stdc++.h>
using namespace std;
int n,k;

vector<int> e[100001];

int ans,dp[100001];
void dfs(int x,int p){
	dp[x]=1;
	for(int it:e[x])
		if(it!=p){
			dfs(it,x);
			if(x==1)	continue;
			if(dp[it]==k)
				ans++;
			else
				dp[x]=max(dp[it]+1,dp[x]);
		}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		if(i==1){
			ans+=x!=1;
			continue;
		}
		e[x].emplace_back(i);
		e[i].emplace_back(x);
	}
	dfs(1,0);
	cout<<ans<<endl;
}
