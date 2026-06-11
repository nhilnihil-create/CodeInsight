#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define fi first
#define se second
#define INF 1000000009
#define LLINF 1000000000000000009LL
using ll = long long;

int main(){
  ll ans=LLINF;
  ll h,w;
  cin>>h>>w;
  if(h%3==0)ans=0;
  else chmin(ans,w);
  if(w%3==0)ans=0;
  else chmin(ans,h);
  for(ll i=0;i<=w;i++){
    ll a=h/2*i;
    ll b=(h+1)/2*i;
    ll c=h*(w-i);
    chmin(ans,max(a,max(b,c))-min(a,min(b,c)));
  }
  for(ll i=0;i<=h;i++){
    ll a=w/2*i;
    ll b=(w+1)/2*i;
    ll c=w*(h-i);
    chmin(ans,max(a,max(b,c))-min(a,min(b,c)));
  }
  cout<<ans<<endl;
  return(0);
}
