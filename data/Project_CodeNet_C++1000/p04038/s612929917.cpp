#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=2005,mod=1e9+7;
ll jc[N*N],num[N*N],dp[N][N],n,k;
ll addd(ll x,ll y){
	x+=y;
	return x%mod;
}
ll ksm(ll y,ll x){
	ll ans=1;
	while(x>0){
		if(x&1)ans=(ans*y)%mod;
		x>>=1;
		y=(y*y)%mod;
	}
	return ans;
}
ll get(int x,int y){
	return jc[x]*num[y]%mod*num[x-y]%mod;
}
int main(){
	int i,j;
	jc[0]=1;
	for (i=1;i<=4000010;i++)jc[i]=jc[i-1]*i%mod;
	num[4000010]=ksm(jc[4000010],mod-2);
	for (i=4000010;i;i--)num[i-1]=num[i]*i%mod;
	scanf("%lld%lld",&n,&k);
	if(k==1){
		puts("1\n");
		return 0;
	}
	dp[0][0]=1;
	for (i=0;i<=n;i++)
		for (j=i;j>=0;j--)
			if(dp[i][j]){
				dp[i+1][j+1]=addd(dp[i+1][j+1],dp[i][j]*(n-i)%mod*get(k*(i+1)-j-2,k-2)%mod);
				if(j)dp[i][j-1]=addd(dp[i][j-1],dp[i][j]);
			}
	printf("%lld\n",dp[n][0]);
	return 0;
}