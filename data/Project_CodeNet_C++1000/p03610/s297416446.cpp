#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i<(n); ++i)

int main() {
  string s; cin >> s;
  string ans;
  rep(i,s.size()){
    if(i==0 || i%2==0) ans += s.at(i);
  }
  cout << ans << endl;
  
  return 0;
}