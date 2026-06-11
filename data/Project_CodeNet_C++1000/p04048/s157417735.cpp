#include <bits/stdc++.h>
#define res register ll
#define ll long long
using namespace std;
ll n,x,ans;
inline void dfs(res l,res s){
  if(l%s==0){
    ans+=(l<<1)-s;
    return;
  }
  ans+=l/s*s*2;
  dfs(s,l%s);
}
int main(){
  scanf("%lld %lld",&n,&x);
  ans=n;
  if(x>=n-x) dfs(x,n-x);
  else  dfs(n-x,x);
  printf("%lld\n",ans);
  return 0;
}