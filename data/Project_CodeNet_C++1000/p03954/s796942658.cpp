/**
 *    author:  tourist
 *    created: 01.01.2020 20:27:38       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(2 * n - 1);
  for (int i = 0; i < 2 * n - 1; i++) {
    cin >> a[i];
  }
  int low = 1, high = 2 * n - 1;
  while (low < high) {
    int mid = (low + high + 1) >> 1;
    int me = (a[n - 1] >= mid);
    int val = n - 1;
    for (int d = 1; d <= n - 1; d++) {
      for (int sign = -1; sign <= 1; sign += 2) {
        int them = (a[n - 1 + sign * d] >= mid);
        if ((them ^ (d % 2)) != me) {
          val = d - 1;
          break;
        }
      }
      if (val != n - 1) {
        break;
      }
    }
    bool one = me ^ (val % 2);
    if (one) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  cout << low << '\n';
  return 0;
}
