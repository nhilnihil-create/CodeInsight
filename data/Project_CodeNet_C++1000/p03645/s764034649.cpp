#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m; cin >> n >> m;
  map<int,set<int>> ms;
  string ans = "IMPOSSIBLE";
  rep(i,m) {
    int a, b; cin >> a >> b;
    ms[a].insert(b);
    ms[b].insert(a);
  }
  for (auto a : ms[1]) {
    if (ms[a].count(n)) {
      ans = "POSSIBLE";
      break;
    }
  }
  cout << ans << endl;
  return 0;
}