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
  int N,t; cin >> N;
  vector<int> e,o;
  rep(i,N) {
    cin >> t;
    if (i%2==0) o.push_back(t);
    else e.push_back(t);
  }
  if (o.size() > e.size()) {
    reverse(o.begin(),o.end());
    for (auto ans:o) cout << ans << ' ';
    for (auto ans:e) cout << ans << ' ';
  }
  else {
    reverse(e.begin(),e.end());
    for (auto ans:e) cout << ans << ' ';
    for (auto ans:o) cout << ans << ' ';
  }
  cout << endl;
}