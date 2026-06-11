#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);


int main() {
  string s, t;
  cin >> s >> t;
  if(s.size()-t.size()==0) {
    rep(i,s.size()){
      cout << s[i] << t[i];
    }
    return 0;
  }
  else {
    rep(i,t.size()){
      cout << s[i] << t[i];
    }
    cout << s[s.size()-1];
  }
  return 0;
}