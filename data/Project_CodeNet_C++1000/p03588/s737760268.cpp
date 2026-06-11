#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i] >> b[i];

  int mn = 0, mx = 0;
  for (int i = 1; i < n; ++i) {
    if (b[i] < b[mn])
      mn = i;
    if (b[i] > b[mx])
      mx = i;
  }

  cout << a[mx] + b[mn] + (a[mn] - a[mx]) << endl;
}