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
  string s;
  cin >> s;
  int n = s.size();
  if (n==2&&s[0]==s[1]) {
    cout << 1 << ' ' << 2 <<endl;
    return 0;
  }
  rep(i,n-2) {
    if (s[i]==s[i+1]||s[i]==s[i+2]) {
      cout << i+1 << ' ' << i+3 << endl;
      return 0;
    }
  }
  cout << -1 << ' ' << -1 << endl;
}