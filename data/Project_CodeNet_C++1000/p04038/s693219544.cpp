#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2005,mod=1e9+7;
int n,k,f[N][N],fac[N*N],ifac[N*N];
int Pow(int x,int k){
	int ret=1;
	while(k){
		if(k&1)ret=(ll)ret*x%mod;
		k>>=1;x=(ll)x*x%mod;
	}
	return ret;
}
int C(int n,int m){
	if(n<m)return 0;
	return (ll)fac[n]*ifac[n-m]%mod*ifac[m]%mod;
}
int main(){
	scanf("%d%d",&n,&k);
	fac[0]=1;
	for(int i=1;i<=n*k;i++)fac[i]=(ll)fac[i-1]*i%mod;
	for(int i=0;i<=n*k;i++)ifac[i]=Pow(fac[i],mod-2);
	if(k==1){
		puts("1");
		return 0;
	}
	f[0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=i;j<=n;j++){
			f[i+1][j]=(f[i+1][j]+f[i][j])%mod;
			f[i][j+1]=(f[i][j+1]+(ll)f[i][j]*C((k-1)*j+i+k-2,k-2))%mod;
		}
	cout<<(ll)f[n][n]*fac[n]%mod<<"\n";
}