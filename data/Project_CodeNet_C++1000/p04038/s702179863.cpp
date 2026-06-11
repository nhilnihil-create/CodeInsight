#include <bits/stdc++.h>
using namespace std;
const int N=2005,mod=1e9+7;
int f[N][N],fac[N*N],ifac[N*N];
int Pow(int x,int k){
	int ret=1;
	while(k){
		if(k&1)ret=1ll*ret*x%mod;
		k>>=1;x=1ll*x*x%mod;
	}
	return ret;
}
int C(int n,int m){
	if(n<m)return 0;
	return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main(){
	fac[0]=1;
	for(int i=1;i<=4000000;i++)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[4000000]=Pow(fac[4000000],mod-2);
	for(int i=3999999;~i;i--)ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	int n,m;scanf("%d%d",&n,&m);
	if(m==1)cout<<1<<"\n",exit(0);
	f[0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(j<i)f[i][j+1]=(f[i][j+1]+f[i][j])%mod;
			f[i+1][j]=(f[i+1][j]+1ll*C(i*(m-1)+j+m-2,m-2)*f[i][j])%mod;
		}
	}
	cout<<1ll*f[n][n]*fac[n]%mod<<"\n";
}