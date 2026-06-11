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

  int n, m;
  cin >> n >> m;
  vector<int> v(n, 1);
  vector<bool> b(n, false);
  b[0] = true;

  rep(i, 0, m) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (b[x] == true)
      b[y] = true;
    v[y]++;
    v[x]--;
    if (v[x] == 0)
      b[x] = false;
  }

  int ans = 0;
  rep(i, 0, n) {
    if (b[i])
      ans++;
  }
  cout << ans << endl;
}
