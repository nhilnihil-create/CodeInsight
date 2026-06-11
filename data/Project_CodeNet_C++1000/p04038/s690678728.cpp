#include<bits/stdc++.h>
#define ll long long
#define pi acos(-1)
using namespace std;
const int mod=1e9+7;
const int N=2005;
inline ll rd(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=0;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return f?x:-x;
}int n,k,mx;
ll f[N][N],fac[N*N],inv[N*N];
inline ll kasumi(ll x,int mi){
	ll res=1;
	while(mi){
		if(mi&1) res=res*x%mod;
		x=x*x%mod;mi>>=1;
	}return res;
}
inline ll C(int n,int m){
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	n=rd(),k=rd();mx=n*k;
	if(k==1){
		puts("1");
		return 0;
	}fac[0]=inv[0]=1;
	for(int i=1;i<=mx;i++) fac[i]=fac[i-1]*i%mod;
	inv[mx]=kasumi(fac[mx],mod-2);
	for(int i=mx-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			f[i][j]=(f[i][j]+f[i-1][j])%mod;
			if(j){
				f[i][j]=(f[i][j]+1ll*f[i][j-1]*(n-(j-1))%mod*C(n*k-i-(j-1)*(k-1)-1,k-2)%mod)%mod;
			}
		}
	}cout<<f[n][n];
	return 0;
}