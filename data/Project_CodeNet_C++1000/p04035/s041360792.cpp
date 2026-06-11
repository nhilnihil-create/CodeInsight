/**
 *    author:  tourist
 *    created: 18.01.2020 23:20:51       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, l;
  cin >> n >> l;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] + a[i + 1] >= l) {
      cout << "Possible" << '\n';
      for (int j = 0; j < i; j++) {
        cout << j + 1 << '\n';
      }
      for (int j = n - 2; j >= i; j--) {
        cout << j + 1 << '\n';
      }
      return 0;
    }
  }
  cout << "Impossible" << '\n';
  return 0;
}
