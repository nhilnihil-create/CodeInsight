#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;
const int Mod=1e9+7,N=2005,Maxn=4000000;
int n,k;
long long dp[N][N],f[Maxn+5],i_f[Maxn+5];
inline long long C(int n,int m)
{
  return (((f[m]*i_f[n])%Mod)*i_f[m-n])%Mod;
}
long long power(long long x,int P)
{
  long long ans=1,m=x;
  while(P)
  {
    if(P&1) (ans*=m)%=Mod;
    P>>=1;
    (m*=m)%=Mod;
  }
  return ans;
}
int main()
{
  scanf("%d%d",&n,&k),f[0]=1;
  if(k==1)return puts("1"),0;
  for(int i=1; i<=Maxn; ++i) f[i]=(f[i-1]*i)%Mod;
  i_f[Maxn]=power(f[Maxn],Mod-2);
  for(int i=Maxn-1; i>=0; --i) i_f[i]=(i_f[i+1]*(i+1))%Mod;
  dp[0][0]=1;
  for(int i=1; i<=n; ++i)
  {
    for(int j=0; j<=i; ++j)
    {
      dp[i][j]=dp[i-1][j];
      if(!j) continue;
      (dp[i][j]+=dp[i][j-1]*(n-j+1)%Mod*C(k-2,n-i+(n-j+1)*(k-1)-1)%Mod)%=Mod;
    }
  }
  return printf("%lld\n",dp[n][n]),0;
}