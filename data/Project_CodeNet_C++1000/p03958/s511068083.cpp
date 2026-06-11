#include <bits/stdc++.h>
using namespace std;

int main() {
  int k, t;
  cin >> k >> t;

  vector<int> a(t);
  for (int i = 0; i < t; ++i)
    cin >> a[i];

  sort(a.rbegin(), a.rend());

  int diff = a[0];
  for (int i = 1; i < t; ++i)
    diff = abs(diff - a[i]);
  int ans = max(0, diff - 1);
  cout << ans << endl;
}