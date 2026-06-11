#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=2005,M=N*N,mod=1e9+7;
int upt(int x)
{while(x>=mod)x-=mod;while(x<0)x+=mod;return x;}
int pw(int x,int k)
{int ret=1;while(k){if(k&1)ret=(ll)ret*x%mod;x=(ll)x*x%mod;k>>=1;}return ret;}

int n,k,jc[M],jcn[M],dp[N][N];
void init()
{
  int lm=n*k;
  jc[0]=1;for(int i=1;i<=lm;i++)jc[i]=(ll)jc[i-1]*i%mod;
  jcn[lm]=pw(jc[lm],mod-2);
  for(int i=lm-1;i>=0;i--)jcn[i]=(ll)jcn[i+1]*(i+1)%mod;
}
int C(int n,int m)
{
  if(n<0||m<0||n<m)return 0;
  return (ll)jc[n]*jcn[m]%mod*jcn[n-m]%mod;
}
int main()
{
  scanf("%d%d",&n,&k); if(k==1){puts("1");return 0;}
  init();
  dp[0][0]=1;
  for(int i=0;i<=n;i++)
    for(int j=0;j<=i;j++)
      {
	if(!dp[i][j])continue;int tp=dp[i][j];
	if(i<n)dp[i+1][j]=upt(dp[i+1][j]+tp);
	if(j<i)
	  {
	    int ml=C((n-j)*(k-1)+n-i-1,k-2);
	    dp[i][j+1]=(dp[i][j+1]+(ll)ml*tp)%mod;
	  }
      }
  printf("%lld\n",(ll)dp[n][n]*jc[n]%mod);
  return 0;
}
