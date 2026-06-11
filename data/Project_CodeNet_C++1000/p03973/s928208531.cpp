#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n; cin >> n;
  VI a(n); for (int i = 0; i < n; i++) cin >> a[i];
  
  lint res = 0;
  int p = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] == p) {
      p++;
    } else {
      res += (a[i] - 1) / p;
    }
    p = max(2, p);
  }
  cout << res << '\n';
  return 0;
}