#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
#ifdef _DEBUG
#include "debug.hpp"
#else
#define debug(...)
#endif
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> rates(9, 0);

  while (n--) {
    int rate;
    cin >> rate;
    if (rate >= 3200)
      rates.at(8)++;
    else
      rates.at(rate / 400)++;
  }

  int kind = 0;
  for (size_t i = 0; i < rates.size() - 1; i++) {
    if (rates.at(i) != 0)
      kind++;
  }

  // all rate are over 3200, minv is 1 ?
  cout << max(kind, 1) << " " << kind + rates.back() << endl;
}

void wrapper() {
  rep(i, 4) {
    cout << "[TEST " << (i + 1) << "]\n";
    solve();
    cout << "\n";
  }
}

int main() {
  fastIO;
#ifdef _DEBUG
  wrapper();
#else
  solve();
#endif
}
