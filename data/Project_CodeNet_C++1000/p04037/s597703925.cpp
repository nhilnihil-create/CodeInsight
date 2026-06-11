#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;


int main() {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int x = n - 1;
  sort(a.begin(), a.end(), greater<int>());
  for (int i = 0; i + 1 < n; ++i) {
    if (a[i + 1] <= i + 1) {
      x = i;
      break;
    }
  }
  int cnt = 0;
  for (int i = x + 1; i < n; ++i) {
    if (a[i] > x) {
      ++cnt;
    }
  }
  if ((a[x] - x - 1) % 2 == 0 && cnt % 2 == 0) {
    cout << "Second\n";
  } else {
    cout << "First\n";
  }
  return 0;
}
