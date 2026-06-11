#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (i * j + (n - i) * (m - j) == k) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}