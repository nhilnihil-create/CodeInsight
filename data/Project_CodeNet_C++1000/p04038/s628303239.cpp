#include<bits/stdc++.h>
#define inf 0x7fffffff
#define RG register
#define inf 0x7fffffff
#define mkp make_pair
#define maxn 100205
typedef unsigned int U;
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const  double eps = 1e-8;
const double pi = acos(-1);
inline ll read(){
    ll x = 0, f = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0') {if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x *10 + ch -'0';ch = getchar();}
    return x * f;
}
int n,k;
int fac[4000005],inv[4000005];
int f[2005][2005];
int qpow(int a,int b){
	int ans=1,base=a;
	while(b){
		if(b&1) ans=1ll*ans*base%mod;
		base=1ll*base*base%mod;
		b>>=1;
	}
	return ans;
}
int C(int n,int m){return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;}
int main(){
	int i,j,u,v,e,w;
	//freopen("a.out","r",stdin);
	//freopen("a.ans","w",stdout);n
	n=read(),k=read();
	if(k==1) {puts("1");return 0;}
	fac[0]=1;
	for(i=1;i<=n*k;i++) fac[i]=1ll*fac[i-1]*i%mod;
	inv[n*k]=qpow(fac[n*k],mod-2);
	for(i=n*k-1;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
	f[0][0]=1;
	for(i=0;i<=n;i++){
		for(j=i;j<=n;j++){
			if(i+1<=j) f[i+1][j]=(f[i+1][j]+f[i][j])%mod;
			if(j+1<=n) f[i][j+1]=(f[i][j+1]+1ll*f[i][j]*C(i+(k-1)*j+k-2,k-2)%mod)%mod;
		}
	}
	printf("%d\n",1ll*f[n][n]*fac[n]%mod);
	return 0;
}
/*
8
0 0 0 0
0 0 1 1
0 1 0 1
0 1 1 0
1 0 0 1
1 0 1 0
1 1 0 0
1 1 1 1
*/