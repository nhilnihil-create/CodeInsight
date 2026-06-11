#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int ans=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch))ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
	return ans*w;
}
const int N=2005,Maxn=2000*2000+1e5+5,mod=1e9+7;
int n,k,f[N][N],fac[Maxn],ifac[Maxn];
inline int C(int n,int m){return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
int main(){
	n=read(),k=read(),ifac[0]=fac[0]=fac[1]=ifac[1]=1;
	if(k==1)return puts("1"),0;
	for(int i=2;i<=Maxn-5;++i)fac[i]=1ll*fac[i-1]*i%mod,ifac[i]=1ll*(mod-mod/i)*ifac[mod%i]%mod;
	for(int i=2;i<=Maxn-5;++i)ifac[i]=1ll*ifac[i]*ifac[i-1]%mod;
	f[1][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=i;++j){
			if(i^j)(f[i][j+1]+=f[i][j]%=mod);
			if(i^n)(f[i+1][j]+=1ll*f[i][j]*C((k-2)+(i*(k-1)+j),k-2)%mod)%=mod;
		}
	cout<<1ll*f[n][n]*fac[n]%mod;
	return 0;
}