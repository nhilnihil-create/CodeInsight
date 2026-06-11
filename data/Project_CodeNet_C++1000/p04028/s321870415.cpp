#include<iostream>
using namespace std;
const int mod=1e9+7;
const int N=5005;
long long dp[N][N];
int main(){
	int n,i,j,k,l;
	cin>>n;
	string s;
	cin>>s;
	l=s.size();
	dp[0][0]=1;
	for(i=1;i<=n;i++){
		dp[i][0]=(dp[i-1][1]+dp[i-1][0])%mod;
		for(j=1;j<=n;j++){
			dp[i][j]=(dp[i-1][j-1]*2+dp[i-1][j+1])%mod;
		}
	}
	for(i=1;i<=l;i++){
		dp[n][l]=(dp[n][l]*(mod+1)/2)%mod;
	}
	cout<<dp[n][l];
}