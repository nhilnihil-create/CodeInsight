#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <map>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

ll N, X;

int main() {
  cin >> N >> X;

  vector<int> costs;
  int a;
  ll ans = 0;

  for (int i = 0; i < N; ++i) {
    cin >> a;
    ans += a;

    costs.push_back(a);
  }

  for (int i = 1; i <= N - 1; ++i) {
    ll cost = 0;
    vector<int> cands;
    cands = costs;

    for (int j = 0; j < N; ++j) {
      int u = (j + 1) % N;

      if (costs[u] > costs[j]) {
        cands[u] = costs[j];
      }

      cost += cands[u];
    }

    ll v = cost + i * X;
    ans = min(ans, v);

    costs = cands;
  }

  cout << ans << endl;

  return 0;
}
