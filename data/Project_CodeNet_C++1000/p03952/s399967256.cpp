#include <bits/stdc++.h>

using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  if (1 < x && x < n + n - 1) {
    cout << "Yes\n";
    vector<int> ans(n + n + 1, -1);
    x--;
    if (x == 1) {
      ans[n - 1] = x;
      ans[n - 2] = x + 1;
      ans[n] = x - 1;
      ans[n + 1] = x + 2;
      int m = 0;
      for (int i = 0; i < n + n - 1; i++) {
        while (x - 1 <= m && m <= x + 2) {
          m++;
        }
        if (ans[i] == -1) {
          ans[i] = m++;
        }
      }
    } else {
      ans[n - 1] = x;
      ans[n - 2] = x - 1;
      ans[n] = x + 1;
      ans[n + 1] = x - 2;
      int m = 0;
      for (int i = 0; i < n + n - 1; i++) {
        while (x - 2 <= m && m <= x + 1) {
          m++;
        }
        if (ans[i] == -1) {
          ans[i] = m++;
        }  
      }
    }
    for (int i = 0; i < n + n - 1; i++) {
      cout << ans[i] + 1 << '\n';
    }
  } else {
    cout << "No\n";
  }
  return 0;
}