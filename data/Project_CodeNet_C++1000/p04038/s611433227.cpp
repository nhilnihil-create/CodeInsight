#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N=2005;
const int MOD=1e9+7;

int n,k,f[N][N],fac[N*N],inv[N*N];

inline int fast_pow(int x,int y){
	int ret=1;
	for(;y;y>>=1){
		if(y&1) ret=(LL)ret*x%MOD;
		x=(LL)x*x%MOD;
	}	
	return ret;
}

inline int C(int x,int y){
	return 1ll*fac[x]*inv[y]%MOD*inv[x-y]%MOD;	
}

int main(){
	scanf("%d%d",&n,&k); if(k==1) {puts("1"); return 0;}
	f[0][0]=1; fac[0]=1;
	for(int i=1;i<=n*k;i++) fac[i]=1ll*fac[i-1]*i%MOD;
	inv[n*k]=fast_pow(fac[n*k],MOD-2);
	for(int i=n*k-1;~i;i--) inv[i]=1ll*inv[i+1]*(i+1)%MOD;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++){
			if(j!=i) f[i][j]=1ll*f[i-1][j]*(n-i+1)%MOD;
			if(j!=0) (f[i][j]+=1ll*f[i][j-1]*C(n*k-(i+(j-1)*(k-1))-1,k-2)%MOD)%=MOD;
		}
	printf("%d\n",f[n][n]);
	return 0;
}	