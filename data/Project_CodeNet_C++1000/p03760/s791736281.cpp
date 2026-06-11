#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string o, e; cin >> o >> e;
  rep(i,o.size()) {
    cout << o[i];
    if (i < e.size()) cout << e[i];
  }
  cout << endl;
  return 0;
}