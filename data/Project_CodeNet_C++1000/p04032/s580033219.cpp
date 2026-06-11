#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;
#define ll long long

signed main() {
  string s;
  cin >> s;
  int st = 0;
  int ed = 1;
  rep(i, s.length()-1) {
    if(s[st]==s[ed]) {
      cout << st+1<<" "<<ed+1 << endl;
      return 0;
    }
    st++;
    ed++;
  }
  st = 0;
  ed = 2;
  rep(i, s.length()-2) {
    if(s[st]==s[ed]) {
      cout << st+1<<" "<<ed+1 << endl;
      return 0;
    }
    st++;
    ed++;
  }
  cout << "-1 -1" << endl;
  return 0;
}