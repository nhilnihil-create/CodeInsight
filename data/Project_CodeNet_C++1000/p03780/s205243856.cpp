#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int l = 0, r = n;
  while (l < r) {
    int c = (l + r) / 2;
    if (a[c] >= k) {
      r = c;
      continue;
    }
    bool dp[k] = {};
    dp[0] = true;
    for (int i = 0; i < n; i++) {
      if (i == c) continue;
      for (int j = k-1; j >= 0; j--) {
        if (j + a[i] < k && dp[j]) dp[j + a[i]] = true;
      }
    }
    bool flag = false;
    for (int i = k-a[c]; i < k; i++) {
      if (dp[i]) flag = true;
    }
    if (flag) r = c;
    else l = c + 1;
  }
  cout << r << endl;
}