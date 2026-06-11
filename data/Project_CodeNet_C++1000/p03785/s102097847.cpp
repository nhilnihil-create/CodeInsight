#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, c, k;
  cin >> n >> c >> k;
  int t[n];
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  sort(t, t + n);

  int bus = 0;
  int man = 0;
  while (man < n) {
    bus++;
    int fst = man;  // 最初に乗る人

    // 到着順に乗れるだけ乗っていく
    while (1) {
      man++;
      if (man >= n) break;             // 最後の人
      if (t[man] - t[fst] > k) break;  // 最初の人からk分以内
      if (man - fst >= c) break;       // 一度にc人まで
    }
  }

  cout << bus << endl;
  return 0;
}
