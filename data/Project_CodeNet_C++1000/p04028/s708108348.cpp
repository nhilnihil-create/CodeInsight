#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005,M=1e9+7;
int n,dp[N][N],k;
char s[N];
signed main(){
	scanf("%lld",&n);
	scanf("%s",s+1);
	int k=strlen(s+1);
	dp[0][0]=1; 
	for (int i=1;i<=n;i++)
		for (int j=0;j<=i;j++){
			if (!j)dp[i][j]=(dp[i-1][0]+dp[i-1][1])%M;
			else dp[i][j]=(2*dp[i-1][j-1]+dp[i-1][j+1])%M;
		}
	for (int i=1;i<=k;i++)(dp[n][k]*=(M/2+1))%=M;
	printf("%lld\n",dp[n][k]);
}