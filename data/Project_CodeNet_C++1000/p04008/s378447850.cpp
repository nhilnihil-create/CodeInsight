#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int ans = 0;
int N,K;

void dfs(vector<int> &dp,vector<vector<int>> &E,int now,int p){
	for(int i=0;i<E[now].size();i++){
		dfs(dp,E,E[now][i],now);
		dp[now] = max(dp[now],dp[E[now][i]]+1);
	}
	if(dp[now]==K-1&&p!=0&&now!=0){
		dp[now] = -1;
		ans++;
	}
}

int main(){
	
	
	cin>>N>>K;
	
	vector<vector<int>> E(N,vector<int>());
	
	for(int i=0;i<N;i++){
		int a;
		cin>>a;
		a--;
		if(i==0){
			if(a!=0)ans++;
		}
		else{
			E[a].push_back(i);
		}
	}

	vector<int> dp(N,0);
	dfs(dp,E,0,-1);

	cout<<ans<<endl;
	
	return 0;
}