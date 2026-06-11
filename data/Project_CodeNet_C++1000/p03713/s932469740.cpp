#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

//vector出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){
  o<<"{";
  for(int i=0;i<(int)v.size();i++) o << (i>0?", ":"") << v[i];
  o<<"}";
  return o;
}


ll solve(ll h, ll w) {
  ll res=1000000000000,s1,s2,s3;
  rep2(i,1,w) {
    s1=h*i;
    s2=h*((w-i)/2);
    s3=h*(w-i-(w-i)/2);
    chmin(res,max({s1,s2,s3}) - min({s1,s2,s3}));
    s2=(w-i)*(h/2);
    s3=(w-i)*(h-h/2);
    chmin(res,max({s1,s2,s3}) - min({s1,s2,s3}));
    // cout << tmp << ' ' << res << endl;
  }
  return res;
}


int main() {
  ll H,W,ans=10000000000;
  cin >> H >> W;
  chmin(ans,solve(H,W));
  chmin(ans,solve(W,H));
  cout << ans << endl;
}