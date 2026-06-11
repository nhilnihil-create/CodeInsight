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

  int a, b, c;
  cin >> a >> b >> c;

  if (a % 2 == 0 && a == b && b == c) {
    cout << -1 << endl;
    return 0;
  }

  if (a & 1 || b & 1 || c & 1) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 1;
  while (true) {
    int aa = a / 2, bb = b / 2, cc = c / 2;
    if ((aa & 1 && bb & 1 && cc & 1) ||
        (aa % 2 == 0 && bb % 2 == 0 && cc % 2 == 0)) {
      a = bb + cc;
      b = aa + cc;
      c = aa + bb;
      ans++;
    } else {
      cout << ans << endl;
      return 0;
    }
  }
}
