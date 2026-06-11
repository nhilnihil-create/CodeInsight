#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5010;
const int mod=1e9+7;
ll dp[N][N];
char s[N];
int n;
int main()
{
	//freopen("H:\\c++1\\in.txt","r",stdin);
	//freopen("H:\\c++1\\out.txt","w",stdout);
	dp[0][0]=1;
	scanf("%d",&n);
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++){
		if(j==0)dp[i+1][j]=(dp[i][j]+dp[i+1][j])%mod;
		else{
			dp[i+1][j-1]=(dp[i][j]*2+dp[i+1][j-1])%mod;
		}
		dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%mod;
	}
	printf("%lld\n",dp[n][len]);
	return 0;
}
