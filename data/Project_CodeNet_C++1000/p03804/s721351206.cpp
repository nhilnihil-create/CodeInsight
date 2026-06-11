#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  bool ok = false;

  for (int i = 0; i + m - 1 < n; ++i) {
    for (int j = 0; j + m - 1 < n; ++j) {
      bool contained = true;
      rep(k, m) rep(l, m) if (a[i+k][j+l] != b[k][l]) contained = false;
      if (contained) ok = true;
    }
  }
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}