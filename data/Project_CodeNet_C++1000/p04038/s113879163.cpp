#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=2200;
const int MAXN=4e6;
const int M=1e9+7;
ll fac[N*N],inv[N*N],f[N][N];
int n,k;
inline ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans=ans*a%M;
		b>>=1;a=a*a%M;
	} 
	return ans;
}
void init(){
	fac[0]=1;
	for(int i=1;i<=MAXN;i++) fac[i]=fac[i-1]*i%M;
	inv[MAXN]=qpow(fac[MAXN],M-2); 
	for(int i=MAXN;i>=1;i--) inv[i-1]=inv[i]*i%M;
}
inline ll C(int n,int m){
	if(n<m) return 0;
	return fac[n]*inv[m]%M*inv[n-m]%M;
}
int main(){
//	freopen("at2000.in","r",stdin);
	init();
	scanf("%d%d",&n,&k);f[0][0]=1;
	if(k==1) {printf("1\n");return 0; } 
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++) f[i][j]=(f[i-1][j]+(n-j+1)*C(n*k-i-(j-1)*(k-1)-1,k-2)%M*f[i][j-1])%M;
	printf("%lld\n",f[n][n]);
	return 0;
}