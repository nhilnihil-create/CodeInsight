#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  ll x,y; cin>>x>>y;
  ll ans=abs(abs(x)-abs(y));
  if(0<=x&&x<y) {cout<<ans<<endl; return 0;}
  if(x<0&&0<y) {cout<<ans+1<<endl; return 0;}
  if(x<y&&y<=0) {cout<<ans<<endl; return 0;}
  if(0<y&&y<x) {cout<<ans+2<<endl; return 0;}
  if(y<=0&&0<=x) {cout<<ans+1<<endl; return 0;}
  if(y<x&&x<0) {cout<<ans+2<<endl; return 0;}
}
