#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define debug(x) cout<<#x<<"="<<x<<endl;
#define chk() cout<<C((n-j+1)*(k-1)+(n-i)-1,k-2)<<endl;
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^'0');
	return x*f;
}
const int maxn=2010;
const int mod=1e9+7;
int ifac[maxn*maxn],fac[maxn*maxn],inv[maxn*maxn];
int f[maxn][maxn];
inline int C(int n,int m){
	if(m==0)return 1;
	if(n<m)return 0;
	return 1ll*fac[n]*ifac[n-m]%mod*ifac[m]%mod;
}
int n,k;
inline void init(){
	n=read(),k=read();
	if(n==0 || k==0)printf("0"),exit(0);
	if(k==1)puts("1"),exit(0);
	inv[0]=inv[1]=1;
	for(register int i=2;i<=maxn*maxn;++i)
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	fac[0]=fac[1]=1;
	for(register int i=2;i<=maxn*maxn;++i)
		fac[i]=1ll*fac[i-1]*i%mod;
	ifac[0]=ifac[1]=1;
	for(register int i=1;i<=maxn*maxn;++i)
		ifac[i]=1ll*ifac[i-1]*inv[i]%mod;

}
inline void solve(){
	f[1][0]=1;
	for(register int i=0;i<=n;++i)
		for(register int j=0;j<=i;++j){
			if(i)(f[i][j]+=f[i-1][j])%=mod;
			if(j)(f[i][j]+=1ll*C((n-j+1)*(k-1)+(n-i)-1,k-2)*f[i][j-1]%mod)%=mod;
		}
	cout<<1ll*f[n][n]*fac[n]%mod;
}
int main(){
	init();
	solve();
	return 0;
}