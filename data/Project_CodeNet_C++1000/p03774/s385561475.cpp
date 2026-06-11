#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const int INF = 100100100;

int main() {
  int N, M, a, b, c, d;
  cin >> N >> M;
  vector<pint> starts(N);
  rep(i, 0, N) {
    cin >> a >> b;
    starts[i] = pint(a, b);
  }
  vector<pint> goals(M);
  rep(i, 0, M) {
    cin >> c >> d;
    goals[i] = pint(c, d);
  }

  rep(i, 0, N) {
    int x1 = starts[i].first, y1 = starts[i].second;
    int ans = 1, mi = abs(x1 - goals[0].first) + abs(y1 - goals[0].second);
    rep(j, 1, M) {
      int x2 = goals[j].first, y2 = goals[j].second;
      int m = abs(x1 - x2) + abs(y1 - y2);
      if (mi > m) {
        mi = m;
        ans = j + 1;
      }
    }

    cout << ans << endl;
  }

  return 0;
}
