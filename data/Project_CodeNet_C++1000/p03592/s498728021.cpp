#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using P = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  bool ok = false;
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      int total = j * (m - i) + i * (n - j);
      if (total == k) ok = true;
    }
  }
  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}