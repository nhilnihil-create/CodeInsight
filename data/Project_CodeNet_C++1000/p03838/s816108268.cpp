#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
const ll inf = 1001001001001001001;
int main(){
  ll x,y;scanf("%lld%lld",&x,&y);
  ll ans = inf;
  if(x <= y) ans = min(ans,y-x);//A
  if(-x <= y) ans = min(ans,y+x+1);//B or BA
  if(-x >= y) ans = min(ans,-y-x+1);//AB
  if(x >= y) ans = min(ans,-y+x+2);//BAB
  printf("%lld\n",ans);
}