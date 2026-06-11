#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2005,mx=4000000,mod=1e9+7;
inline void add(int &x,int y){
	x+=y;if(x>=mod) x-=mod;
}
inline int pls(int x,int y){
	add(x,y);return x;
}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=mul(a,a)) if(b&1) res=mul(res,a);
	return res;
}
int n,k;
int fac[N*N],inv[N*N];
int f[N][N];
inline int C(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return mul(mul(fac[n],inv[m]),inv[n-m]);
}
int main(){
	fac[0]=1;
	for(int i=1;i<=mx;i++) fac[i]=mul(fac[i-1],i);
	inv[mx]=qpow(fac[mx],mod-2);
	for(int i=mx-1;i>=0;i--) inv[i]=mul(inv[i+1],i+1);
	scanf("%d%d",&n,&k);
	if(k==1){puts("1");return 0;}
	for(int i=1;i<=n;i++) f[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			f[i][j]=pls(f[i-1][j],mul(f[i][j-1],mul(n-j+1,C(n*k-i-(j-1)*(k-1)-1,k-2))));
	printf("%lld",f[n][n]);
	return 0;
}