#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int x, y; cin >> x >> y;
  int d = abs(abs(x) - abs(y));
  int ans = d;
  if (x > y) {
    ans++;
    if (y < 0 && x < 0) ans++;
    if (y > 0 && x > 0) ans++;
  }
  if (y > 0 && x < 0) ans++;
  cout << ans << endl;
  return 0;
}