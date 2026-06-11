#include<bits/stdc++.h>
using namespace std;
const int maxn=2003;
const int mod=1e9+7;
int n,K;
int f[maxn][maxn];
int Fac[maxn*maxn],Inv[maxn*maxn];
inline int Pow(int a,int n){
	int ans=1;
	for(;n;n>>=1,a=a*1ll*a%mod)if(n&1)ans=ans*1ll*a%mod;
	return ans;
}
inline int C(int n,int m){
	if(n<m||m<0)return 0;
	return Fac[n]*1ll*Inv[m]%mod*Inv[n-m]%mod;
}
int main(){
	scanf("%d%d",&n,&K);
	if(K==1)return puts("1"),0;
	Fac[0]=1;
	for(int i=1;i<=n*K;i++)Fac[i]=Fac[i-1]*1ll*i%mod;
	Inv[n*K]=Pow(Fac[n*K],mod-2);
	for(int i=n*K-1;i>=0;i--)Inv[i]=Inv[i+1]*(i+1ll)%mod;
	f[0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			(f[i+1][j]+=f[i][j])%=mod;
			f[i][j+1]=(f[i][j+1]+f[i][j]*1ll*C(n*K-(i+j*(K-1))-1,K-2))%mod;
		}
	}
	printf("%lld\n",f[n][n]*1ll*Fac[n]%mod);
	return 0;
}
