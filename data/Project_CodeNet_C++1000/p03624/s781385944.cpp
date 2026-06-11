#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s; cin >> s;
  set<char> u;
  rep(i,s.size()) {
    u.insert(s[i]);
  }
  rep(i,26) {
    if (u.count(char(97+i)) == 0) {
      cout << (char(97+i)) << endl;
      return 0;
    }
  }
  cout << "None" << endl;
  return 0;
}