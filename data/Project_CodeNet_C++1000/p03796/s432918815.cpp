#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  const ll M = 1e9+7;
  int n; cin >> n;
  ll ans = 1;
  for (int i = 1; i<=n; i++) {
    ans = ans * i % M;
  }
  cout << ans << endl;
  return 0;
}