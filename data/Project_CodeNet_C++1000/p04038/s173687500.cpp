#include <bits/stdc++.h>
using namespace std;
#define lor(a,b,c) for(register int a=b;a<=c;++a)
#define ror(a,b,c) for(register int a=c;a>=b;--a)

const int N=2005,K=2005,S=N*K,MOD=1e9+7;
int n,k;
int fac[S],inv[S];
int dp[N][K];

inline int qsm(int a,int b) {int ans=1; while(b) {if(b&1) ans=1ll*ans*a%MOD; a=1ll*a*a%MOD; b>>=1;} return ans;}
inline int C(int a,int b) {return b<0||a<b?0:1ll*fac[a]*inv[b]%MOD*inv[a-b]%MOD;}
inline void inc(int &a,int b) {(a+=b)>=MOD?a-=MOD:a;}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif

	cin>>n>>k;
	if(k==1) return puts("1"),0;
	fac[0]=1l; lor(i,1,n*k) fac[i]=1ll*fac[i-1]*i%MOD;
	inv[n*k]=qsm(fac[n*k],MOD-2); ror(i,0,n*k-1) inv[i]=1ll*inv[i+1]*(i+1)%MOD;
	dp[0][0]=1;
	lor(i,0,n) lor(j,0,i){
		if(i) inc(dp[i][j],dp[i-1][j]);
		if(j) inc(dp[i][j],1ll*dp[i][j-1]*C(n*k-i-(j-1)*(k-1)-1,k-2)%MOD*(n-j+1)%MOD);
	}
	printf("%d\n",dp[n][n]);

	return 0;
}