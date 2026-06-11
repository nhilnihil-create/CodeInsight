#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

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
  ll N;
  cin >> N;
  ll cnt=1,a;
  map<int,int> mp;
  rep(i,N) {
    cin >> a;
    mp[a]++;
  }
  for (auto i=mp.begin();i!=mp.end();i++){
    if (i->first!=0&&i->second!=2) {
      cout << 0 << endl; return 0;
    }
    cnt = cnt*i->second%mod;
  }
  cout << cnt << endl;
}