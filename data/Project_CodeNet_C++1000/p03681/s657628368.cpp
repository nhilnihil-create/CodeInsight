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
  int N,M;
  ll ans=1;
  cin >> N >> M;
  if (abs(N-M)>1) {
    ans=0;
  }
  else if (M==N) {
    rep2(i,1,N+1) {
      ans *= i*i%mod;
      ans%=mod;
    }
    ans*=2;ans%=mod;
  }
  else {
    if (N>M) swap(N,M);
    rep2(i,1,N+1) {
      ans*=i*i%mod;
      ans%=mod;
    }
    ans = ans*M%mod;
  }
  cout << ans << endl;
}