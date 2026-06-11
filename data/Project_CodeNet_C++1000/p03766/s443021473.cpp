#include<bits/stdc++.h>
#define N 1000005
using namespace std;
const int mod=1e9+7;
int dp[N];
long long S;
int main(){
	int n;cin>>n;
	dp[1]=n;dp[2]=n*1LL*n%mod;
	S=dp[1]+dp[2];
	for(int i=3;i<=n;i++)
		dp[i]=((n-1)*1LL*n-(i-1-2)+S-dp[i-2])%mod,S+=dp[i];
	cout<<dp[n]<<endl;
	return 0;
}