/**
 *    author:  tourist
 *    created: 18.01.2020 23:53:34       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  int k = 1;
  while (k + 1 <= n && a[k] >= k + 1) {
    k += 1;
  }
  int up = a[k - 1] - k;
  int right = 0;
  while (k + right < n && a[k + right] == k) {
    ++right;
  }
  cout << (up % 2 == 0 && right % 2 == 0 ? "Second" : "First") << '\n';
  return 0;
}
