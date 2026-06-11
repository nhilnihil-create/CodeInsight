#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> c(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    c[a] += 1;
    c[b] += 1;
  }

  bool ok = true;
  for (int i = 0; i < n; ++i) {
    if (c[i] % 2 != 0) {
      ok = false;
    }
  }

  if (ok) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}