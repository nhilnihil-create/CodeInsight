#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define SF scanf
#define PF printf
#define MAXN 2010
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll dp[MAXN][MAXN];
ll fac[MAXN*MAXN+MAXN*2],inv[MAXN*MAXN+MAXN*2];
ll fsp(ll x,int y){
	ll res=1;
	while(y){
		if(y&1)
			res=res*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return res;
}
ll C(int x,int y){
	return fac[x]*inv[y]%MOD*inv[x-y]%MOD;	
}
int n,k;
int main(){
	fac[0]=1;
	for(int i=1;i<=4004000;i++)
		fac[i]=fac[i-1]*i%MOD;
	inv[4004000]=fsp(fac[4004000],MOD-2);
	for(int i=4004000;i>0;i--)
		inv[i-1]=inv[i]*i%MOD;
	SF("%d%d",&n,&k);
	if(k==1){
		PF("1");
		return 0;
	}
	k--;
	dp[0][0]=1;
	for(int i=0;i<=n;i++)
		for(int j=i;j<=n;j++){
			if(i!=0)
				dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
			if(j!=0)
				dp[i][j]=(dp[i][j]+dp[i][j-1]*C(i+(j-1)*k+k-1,k-1)%MOD)%MOD;
		}
	PF("%lld",dp[n][n]*fac[n]%MOD);
}