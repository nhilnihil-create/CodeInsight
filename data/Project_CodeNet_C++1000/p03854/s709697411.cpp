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


int main() {
  string S;
  cin >> S;
  vector<string> cand={"dreamer","dream","eraser","erase"};
  rep(i,4) reverse(cand[i].begin(),cand[i].end());
  reverse(S.begin(),S.end());
  int now=0;
  while (now<S.size()) {
    bool f=false;
    for(auto i:cand) {
      // cout << S.substr(now,i.size()) << endl << i << endl;
      if (S.substr(now,i.size())==i) {
        f=true;
        now+=i.size();
      }
    }
    if (f) continue;
    else {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
}