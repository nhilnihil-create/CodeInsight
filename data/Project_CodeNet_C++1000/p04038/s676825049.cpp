#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define ll long long
#define re register
#define il inline
#define fp(i,a,b) for(re int i=a;i<=b;++i)
#define fq(i,a,b) for(re int i=a;i>=b;--i)
using namespace std;
const int N=2010,mod=1e9+7;
int n,k,f[N][N],jc[N*N],inv[N*N],gu;
il int gi()
{
  re int x=0,t=1;
  re char ch=getchar();
  while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
  if(ch=='-') t=-1,ch=getchar();
  while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
  return x*t;
}
il ll ksm(re ll S,re ll n)
{
	re ll T=S;S=1;
  while(n)
	{
		if(n&1) S=S*T%mod;
		T=T*T%mod;
		n>>=1;
	}
  return S;
}
il ll C(re int x,re int y)
{
	if(x<0||y<0||x<y) return 0;
	return 1ll*jc[x]*inv[y]%mod*inv[x-y]%mod;
}
int main()
{
  n=gi();k=gi();gu=N*N;
	if(k==1) {puts("1");return 0;}
	jc[0]=inv[0]=1;
	fp(i,1,gu) jc[i]=1ll*jc[i-1]*i%mod;inv[gu]=ksm(jc[gu],mod-2);
	fq(i,gu-1,1) inv[i]=1ll*inv[i+1]*(i+1)%mod;
  f[0][0]=1;
	fp(i,1,n)
		fp(j,0,i)
	{
		(f[i][j]+=f[i-1][j])%=mod;
		if(j) (f[i][j]+=C(n*k-(j-1)*(k-1)-i-1,k-2)*f[i][j-1]%mod*(n-j+1)%mod)%=mod;
	}
  printf("%d\n",f[n][n]);
  return 0;
}
