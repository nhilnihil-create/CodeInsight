#include<bits/stdc++.h>
#define LL long long
#define il inline
#define re register

using namespace std;
const int N=2000+10,mod=1e9+7;
il int rd()
{
  int x=0,w=1;char ch=0;
  while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
  while(ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
  if((x*=w)==-1) exit(0);
  return x;
}
int n,kk,f[N][N],fac[N*N],iac[N*N];
il int fpow(int a,int b){int an=1;while(b){if(b&1) an=1ll*an*a%mod;a=1ll*a*a%mod,b>>=1;}return an;}
il int C(int n,int m){return m<0||n<m?0:1ll*fac[n]*iac[m]%mod*iac[n-m]%mod;}

int main()
{
  n=rd(),kk=rd();
  fac[0]=1;
  for(int i=1;i<=n*kk;++i) fac[i]=1ll*fac[i-1]*i%mod;
  iac[n*kk]=fpow(fac[n*kk],mod-2);
  for(int i=n*kk;i;--i) iac[i-1]=1ll*iac[i]*i%mod;
  f[0][0]=1;
  for(int i=1;i<=n;++i)
	for(int j=0;j<=i;++j)
	  f[i][j]=(f[i-1][j]+(j?(1ll*f[i][j-1]*(n-j+1)%mod*C(n-i+(n-j+1)*(kk-1)-1,kk-2)%mod):0))%mod;
  printf("%d\n",kk>1?f[n][n]:1);
  return 0;
}
