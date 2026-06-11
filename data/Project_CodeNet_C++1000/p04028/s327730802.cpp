#include <bits/stdc++.h>
const int mod=1e9+7;
int n,len,dp[5005][5005];char s[56000];
#define ll long long
ll qpow(int a, int b) {
	if (b==0) return 1;
	ll d=qpow(a,b>>1);d=(d*d)%mod;
	if (b&1) d=(d*(ll)a)%mod;
	return d;
}

int main() {
	scanf("%d%s",&n,s+1);
	dp[0][0]=1;len=std::strlen(s+1);
	for (int i=0;i<=n;++i) {
		for (int j=0;j<=i;++j) {
			dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j]*2)%mod;
			dp[i+1][j-(j>0?1:0)]=(dp[i+1][j-(j>0?1:0)]+dp[i][j])%mod;
		}
	}//printf("%d",dp[n][len]);
	printf("%lld",(ll)dp[n][len]*qpow(qpow(2,len),mod-2)%mod);
	return 0;
}