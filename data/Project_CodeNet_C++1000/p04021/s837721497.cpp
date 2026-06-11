/**
 *    author:  tourist
 *    created: 24.01.2020 23:42:43       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  int diff = 0;
  for (int i = 0; i < n; i++) {
    if (a[i].second % 2 != i % 2) {
      ++diff;
    }
  }
  cout << diff / 2 << '\n';
  return 0;
}
