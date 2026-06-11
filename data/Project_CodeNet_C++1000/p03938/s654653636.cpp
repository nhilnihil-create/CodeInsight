#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> ps(n);
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    p--;
    ps[p] = i;
  }

  vector<int> xs(n);
  vector<int> ys(n);
  for (int i = 1; i < n; i++) {
    int d = ps[i] - ps[i - 1];
    if (d > 0) {
      ys[i] = ys[i - 1] - 1;
      xs[i] = xs[i - 1] + d + 1;
    } else {
      ys[i] = ys[i - 1] + d - 1;
      xs[i] = xs[i - 1] + 1;
    }
  }

  int x_base = 1;
  int y_base = -ys[n - 1] + 1;
  for (int i = 0; i < n; i++) {
    xs[i] += x_base;
    ys[i] += y_base;
  }

  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << xs[i];
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << ys[i];
  }
  cout << endl;
}
