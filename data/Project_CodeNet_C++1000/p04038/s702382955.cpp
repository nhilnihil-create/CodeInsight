#include<bits/stdc++.h>
using namespace std;
int n,m;
inline int read(){
	char c=getchar();int s=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';c=getchar();
	}return s;
}
const int N=2500;
const int mod=1e9+7;
int f[N][N];
int fac[N*N];
int ksm(int x,int y){
	int b=1;
	while(y){
		if(y&1)b=(1ll*b*x)%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}return b;
}
int C(int x,int y){
	return 1ll*fac[x]*ksm(1ll*fac[y]*fac[x-y]%mod,mod-2)%mod;
}
int main(){
	n=read();m=read();
	if(m==1){
		cout<<1;
		return 0;
	}
	f[0][0]=1;fac[0]=1;
	for(int i=1;i<=2000*2000;i++)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=1;i<=n;i++){
		for(int k=0;k<=i;k++){
			f[i][k]=(f[i-1][k]+(k>0?1ll*f[i][k-1]*(n-k+1)%mod*C(n*m-i-(k-1)*(m-1)-1,m-2)%mod:0))%mod;
		}
	}
	cout<<f[n][n];
	return 0;
}