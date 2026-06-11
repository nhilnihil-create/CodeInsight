#include <iostream>
#include <queue>
#include <map>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define in(v) v; cin >> v;
#define rep(i,n) for(int i=0;i<(n);++i)

int main() {
  int in(N);

  map<int, int> m;
  m[-1] = 0;
  m[N] = N;
  priority_queue<pii> q;
  rep(i, N) {
    int in(a);
    q.emplace(-a, i);
  }
  ll ans = 0;
  while (!q.empty()) {
    auto p = q.top(); q.pop();
    m[p.second] = p.second;
    ll l = (--m.lower_bound(p.second))->first, r = m.upper_bound(p.second)->first;
    ans += -1LL * (p.second - l) * (r - p.second) * p.first;
  }
  cout << ans << endl;

  return 0;
}
