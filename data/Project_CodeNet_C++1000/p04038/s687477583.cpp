#include<cstdio>
#include<cstring>
#include<iostream>
#define mod 1000000007
using namespace std;
int n,k,tmp;
long long dp[2005][2005],fact[4000005],inv[4000005];
inline long long quick_pow(long long x,int p){
	long long result=1;
	while(p){
		if(p&1){
			result*=x;
			result%=mod;
		}
		p>>=1;
		x*=x;
		x%=mod;
	}
	return result;
}
inline void init(){
	dp[0][0]=1;
	fact[0]=1;
	for(register int i=1;i<=n*k;i++){
		fact[i]=fact[i-1]*i%mod;
	}
	inv[n*k]=quick_pow(fact[n*k],mod-2);
	for(register int i=n*k-1;i>=0;i--){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
}
inline long long c(int n,int m){
	return (fact[n]*inv[m]%mod)*inv[n-m]%mod;
}
int main(){
	scanf("%d%d",&n,&k);
	if(k==1){
		printf("1\n");
		return 0;
	}
	init();
	for(register int i=1;i<=n;i++){
		for(register int j=0;j<=i;j++){
			if(j==0){
				dp[i][0]=dp[i-1][0];
				continue;
			}
			tmp=n*k-(j-1)*(k-1)-i-1;
			dp[i][j]=(dp[i-1][j]+dp[i][j-1]*(n-j+1)%mod*c(tmp,k-2))%mod;
		}
	}
	printf("%lld\n",dp[n][n]);
	return 0;
}