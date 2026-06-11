#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n, k;
  cin >> n;
  cin >> k;

  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int half = min(x[i], k - x[i]);
    ans += half * 2;
  }
  cout << ans << endl;
}
