#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int dp[5002][5002];

void add(int&x,int y){
	x+=y;
	if(x>=mod) x-=mod;	
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	dp[0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=n;j++){
			add(dp[i+1][j+1],dp[i][j]);
			add(dp[i+1][j+1],dp[i][j]);
			add(dp[i+1][max(0,j-1)],dp[i][j]);
		}
	long long int tmp=dp[n][s.size()];
	for(int i=0;i<s.size();i++)
		tmp=tmp*500000004%mod;
	cout<<tmp<<endl;
	
}
