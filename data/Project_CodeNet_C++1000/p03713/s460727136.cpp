#include<bits/stdc++.h>
#include<iostream>
using namespace std;
 
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

using ll = long long;
 
/****************************************\
| Thank you for viewing my code:)        |
| Written by RedSpica a.k.a. RanseMirage |
| Twitter:@asakaakasaka                  | 
\****************************************/
 
 
signed main() {
  ll h,w;
    cin>>h>>w;
  ll ans=10000000000;

  //縦に3つ
  for(int i=1;i<h-1;i++){
    ll a=i*w;
    ll b=(h-i)/2*w;
    ll c=(h-i-(h-i)/2)*w;
    ll now=max({a,b,c})-min({a,b,c});
    chmin(ans,now);
  }
  //横に3つ
  for(int i=1;i<w-1;i++){
    ll a=i*h;
    ll b=(w-i)/2*h;
    ll c=(w-i-(w-i)/2)*h;
    ll now=max({a,b,c})-min({a,b,c});
    chmin(ans,now);
  }

  //T字
  for(int i=1;i<h;i++){
    ll a=i*w;
    ll b=(w/2)*(h-i);
    ll c=(w-w/2)*(h-i); 
    ll now=max({a,b,c})-min({a,b,c});
    chmin(ans,now);
  }

  //ト
  for(int i=1;i<w;i++){
    ll a=i*h;
    ll b=(h/2)*(w-i);
    ll c=(h-h/2)*(w-i);
    ll now=max({a,b,c})-min({a,b,c});
    chmin(ans,now);
  }
  cout<<ans<<endl;
}