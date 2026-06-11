#include<iostream>
#include<cstdio>
using namespace std;
const int N=2020,mod=1e9+7;
int n,k,f[N][N],fac[N*N],iv[N*N];
int fpow(int x,int y){
	int res=1;
	for(;y;y>>=1,x=1ll*x*x%mod)
		if(y&1)res=1ll*res*x%mod;
	return res;
}
int C(int x,int y){
	return 1ll*fac[x]*iv[y]%mod*iv[x-y]%mod;
}
int main()
{
	cin>>n>>k; fac[0]=iv[0]=1;
	for(int i=1;i<=n*k;i++)
		fac[i]=1ll*fac[i-1]*i%mod,iv[i]=fpow(fac[i],mod-2);
	if(k==1)return puts("1"),0;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++){
			f[i][j]=f[i-1][j];
			if(j)f[i][j]=(f[i][j]+1ll*f[i][j-1]*(n-j+1)%mod*C(n*k-i-1-(j-1)*(k-1),k-2)%mod)%mod;
		}
	cout<<(f[n][n]%mod+mod)%mod<<endl;
	return 0;
}