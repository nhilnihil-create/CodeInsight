#include<cstdio>
#include<cstring>
#define Mod 1000000007
int n,l;
long long f[2][5005],g[5005],h[2][5005],k[5005],ans;
char c[5005];
int main()
{
	scanf("%d",&n);
	scanf("%s",c);l=strlen(c);
	f[0][0]=h[0][0]=g[0]=1;
	for(int i=1;i<=n-l;++i){
		f[i&1][0]=(f[1&i^1][1]+f[1&i^1][0])%Mod;;g[i]=f[i&1][0];
		for(int j=1;j<=i;++j)f[i&1][j]=(f[1&i^1][j+1]+2*f[1&i^1][j-1])%Mod;
	}
	for(int i=1;i<=n;++i){
		h[i&1][0]=0;
		for(int j=1;j<=i;++j)h[i&1][j]=(h[1&i^1][j+1]+2*h[1&i^1][j-1])%Mod;
		k[i]=h[i&1][l];
	}
	for(int i=0;i<=n-l;i+=2)ans=(ans+g[n-l-i]*k[l+i])%Mod;
	for(int i=1;i<=l;++i)ans=ans*(Mod/2+1)%Mod;
	printf("%lld\n",ans);
	return 0;
}