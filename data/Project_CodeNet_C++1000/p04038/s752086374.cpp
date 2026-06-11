#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(4)
#pragma GCC optimize("Ofast,no-stack-protector")
#define ll long long
#define res register ll
#define N 2005
using namespace std;
ll inv[N*N+N+N],jie[N*N+N+N],k,n,f[N][N];
const ll mod=1e9+7;
inline ll read()
{
  ll X=0,w=0;
  char ch=0;
  while(!isdigit(ch))
  {
    w|=ch=='-';
    ch=getchar();
  }
  while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
  return w?-X:X;
}
inline ll quickpow(res base,res num)
{
  res ans=1;
  for(; num; num>>=1,base=1LL*base*base%mod)
    if(num&1)
      ans=1LL*ans*base%mod;
  return ans;
}
inline void init()
{
  jie[0]=jie[1]=inv[0]=inv[1]=1;
  for(res i=2; i<=n*k+n+k; i++)
  {
    jie[i]=1LL*jie[i-1]*i%mod;
    inv[i]=quickpow(jie[i],mod-2);
  }
}
inline ll C(ll m,ll n)
{
  return 1LL*jie[m]*inv[n]%mod*1LL*inv[m-n]%mod;
}
int main()
{
  n=read(),k=read()-1;
  if(!k)
  {
    puts("1");
    return 0;
  }
  init();
  f[0][0]=1;
  for(res i=0; i<=n; i++)
    for(res j=i; j<=n; j++)
    {
      if(i) f[i][j]=(f[i][j]+f[i-1][j])%mod;
      if(j) f[i][j]=(f[i][j]+1LL*f[i][j-1]*C(i+j*k-1,k-1)%mod)%mod;
    }
  printf("%lld\n",1LL*f[n][n]*jie[n]%mod);
  return 0;
}