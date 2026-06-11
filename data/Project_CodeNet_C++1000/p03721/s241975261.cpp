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

ll const mod =1e9+7;
int main() {
  ll N,K,a,b;
  cin >> N >> K;
  map<int,ll> mp;
  rep(i,N) {
    cin >> a >> b;
    mp[a];
    mp[a]+=b;
  }
  ll cnt=0;
  for (auto ix=mp.begin();ix!=mp.end();ix++){
    cnt+=ix->second;
    if (cnt>=K) {
      cout << ix->first << endl;
      return 0;
    }
  }
}