#include <bits/stdc++.h>
using namespace std;

int N,M,Q,v[100009],d[100009],c[100009],dp[100009][19];
vector<int>x[100009];

int main(){
	cin>>N>>M;
	for(int i=1;i<=M;i++){
		int a,b;cin>>a>>b;
		x[a].push_back(b);
		x[b].push_back(a);
	}
	cin>>Q;
	for(int i=1;i<=Q;i++){
		cin>>v[i]>>d[i]>>c[i];
		dp[v[i]][d[i]]=max(dp[v[i]][d[i]],i);
	}
	for(int i=10;i>=1;i--){
		for(int j=1;j<=N;j++){
			dp[j][i-1]=max(dp[j][i-1],dp[j][i]);
			for(int k=0;k<x[j].size();k++){
				dp[x[j][k]][i-1]=max(dp[x[j][k]][i-1],dp[j][i]);
			}
		}
	}
	for(int i=1;i<=N;i++){
		int maxn=0;
		for(int j=0;j<=10;j++) maxn=max(maxn,dp[i][j]);
		cout<<c[maxn]<<endl;
	}
	return 0;
}
