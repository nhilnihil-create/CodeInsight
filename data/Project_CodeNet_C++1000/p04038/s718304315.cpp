#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,N=2002;
int n,k,f[N][N],fac[N*N],inv[N*N],ans;
int C(int n,int m){return n<m?0:1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;}
int main()
{
	scanf("%d%d",&n,&k);
	if(k==1){puts("1");return 0;}
	fac[0]=1;for(int i=1;i<=n*k;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[0]=inv[1]=1;for(int i=2;i<=n*k;i++)inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;
	for(int i=2;i<=n*k;i++)inv[i]=1ll*inv[i-1]*inv[i]%mod;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	for(int j=i;~j;j--)
	f[i][j]=(f[i][j]+1ll*f[i-1][j-1]*C(k*i-j-1,k-2)%mod+f[i][j+1])%mod;
	f[n][0]=1ll*f[n][0]*fac[n]%mod;
	printf("%d",f[n][0]);
}