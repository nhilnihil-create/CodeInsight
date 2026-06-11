#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b1, b2;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    if (i & 1)
      b1.push_back(a[i]);
    else
      b2.push_back(a[i]);
  }

  if (n & 1) {
    reverse(b2.begin(), b2.end());
    for (int i = 0; i < n; i++) {
      if (i < b2.size()) {
        cout << b2[i];
      } else {
        cout << b1[i - b2.size()];
      }
      if (i < n - 1) {
        cout << ' ';
      } else {
        cout << '\n';
      }
    }
  } else {
    reverse(b1.begin(), b1.end());
    for (int i = 0; i < n; i++) {
      if (i < b1.size()) {
        cout << b1[i];
      } else {
        cout << b2[i - b1.size()];
      }
      if (i < n - 1) {
        cout << ' ';
      } else {
        cout << '\n';
      }
    }
  }

  return 0;
}