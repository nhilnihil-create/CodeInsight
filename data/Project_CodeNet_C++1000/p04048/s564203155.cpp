#include <bits/stdc++.h>
#define res register ll
#define ll long long
using namespace std;
ll n,x,ans;
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
inline void dfs(res l,res s)
{
  if(l%s==0)
  {
    ans+=(l<<1)-s;
    return;
  }
  ans+=l/s*s*2;
  dfs(s,l%s);
}
int main()
{
  n=read(),x=read();
  ans=n;
  if(x>=n-x)
    dfs(x,n-x);
  else
    dfs(n-x,x);
  printf("%lld\n",ans);
  return 0;
}