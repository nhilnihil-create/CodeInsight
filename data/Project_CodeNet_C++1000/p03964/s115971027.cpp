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
  int N; cin >> N;

  ll t=1,a=1,x,y;
  vector<vector<int>> TA(N,vector<int>(2));
  rep(i,N) {
    cin >> x >> y;
    ll tt = max({(a+y-1)/y, (t+x-1)/x}); 

    a = tt*y;
    t = tt*x;
    
  }
  cout << t+a << endl;
}