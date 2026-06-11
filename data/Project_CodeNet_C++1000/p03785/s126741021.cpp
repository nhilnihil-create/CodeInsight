#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n, c, k;
  cin >> n >> c >> k;

  vector<int> t(n);
  rep(i, n) cin >> t.at(i);
  sort(t.begin(), t.end());

  int cnt = 1;
  int min_time = t.at(0);
  int canPassenger = c;
  for (int i = 0; i < n; i++) {
    if (canPassenger <= 0 || t.at(i) - min_time > k) {
      cnt++;
      min_time = t.at(i);
      canPassenger = c - 1;
    } else {
      canPassenger--;
    }
  }

  cout << cnt << endl;
  return 0;
}