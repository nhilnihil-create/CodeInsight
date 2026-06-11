#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int g[13] = {};
  g[1] = g[3] = g[5] = g[7] = g[8] = g[10] = g[12] = 1;
  g[4] = g[6] = g[9] = g[11] = 2;
  g[2] = 3;

  int x, y;
  cin >> x >> y;

  if (g[x] == g[y])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
