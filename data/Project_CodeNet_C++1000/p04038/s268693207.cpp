#include<bits/stdc++.h>
#define ll long long
#define N 2005

using namespace std;
inline int Get() {int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}while('0'<=ch&&ch<='9') {x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}return x*f;}

const ll mod=1e9+7;
ll ksm(ll t,ll x) {
	ll ans=1;
	for(;x;x>>=1,t=t*t%mod)
		if(x&1) ans=ans*t%mod;
	return ans;
}
int n,k;
ll fac[N*N],ifac[N*N];
void pre(int n) {
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	ifac[n]=ksm(fac[n],mod-2);
	for(int i=n-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
}
ll C(int n,int m) {return fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
ll f[N][N];
int main() {
	pre(4e6);
	n=Get(),k=Get();
	if(k==1) {
		cout<<1;
	} else {
		f[0][0]=1;
		for(int i=1;i<=n;i++) {
			for(int j=0;j<i;j++) {
				if(!f[i-1][j]) continue ;
//				cout<<"i="<<i<<" j="<<j<<" f="<<f[i-1][j]<<" "<<C(i*(k-1)+j-1,k-2)<<"\n";
				(f[i][j]+=f[i-1][j]*C(i*(k-1)+j-1,k-2))%=mod;
			}
			for(int j=1;j<=i;j++) (f[i][j]+=f[i][j-1])%=mod;
		}
		cout<<f[n][n]*fac[n]%mod;
	}
	return 0;
}
