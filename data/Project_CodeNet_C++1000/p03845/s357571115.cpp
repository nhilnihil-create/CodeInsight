#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> t(n);
  int tot = 0;
  rep(i,n) {
    cin >> t[i];
    tot += t[i];
  }
  int m; cin >> m;
  rep(i,m) {
    int p, x; cin >> p >> x;
    cout << tot - t[p-1] + x << endl;
  }
  return 0;
}