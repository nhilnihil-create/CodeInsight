#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 4000000 
using namespace std;
int n,k;
int dp[2005][2005];
int fac[4000005],ifac[4000005];

int ksm(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod,y/=2;
	}
	return res;
}

int C(int x,int y){
	int res=1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
	return res;
}

int main(){
	scanf("%d %d",&n,&k);
	if(k==1){
		puts("1");return 0;
	}
	fac[0]=1;for(int i=1;i<=maxn;i++) fac[i]=1ll*i*fac[i-1]%mod;
	ifac[maxn]=ksm(fac[maxn],mod-2);
	for(int i=maxn-1;i>=0;i--) ifac[i]=1ll*(i+1)*ifac[i+1]%mod;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			dp[i][j]=dp[i-1][j];
			if(j){
				dp[i][j]+=1ll*dp[i][j-1]*(n-j+1)%mod*C(n*k-i-(j-1)*(k-1)-1,k-2)%mod;
				if(dp[i][j]>=mod) dp[i][j]-=mod;
			}
		}
	}
	printf("%d\n",dp[n][n]);
	
	return 0;
}