#include<bits/stdc++.h>
using namespace std;

int dp[100001];
vector<int> e[100001];
void dfs(int x){
	vector<int> v;
	for(int it:e[x]){
		dfs(it);
		v.emplace_back(dp[it]);
	}
	sort(v.begin(),v.end(),greater<int>());
	for(int i=0;i<v.size();i++)
		dp[x]=max(dp[x],v[i]+i+1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=2,x;i<=n;i++){
		cin>>x;
		e[x].emplace_back(i);
	}
	dfs(1);
	cout<<dp[1]<<endl;
}
