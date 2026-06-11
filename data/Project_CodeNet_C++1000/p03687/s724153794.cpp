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

  string s;
  cin >> s;
  int n = s.size();
  int ans = 1e9;
  rep(i, 0, 26) {
    int c = 0, maxv = 0;
    rep(j, 0, n) {
      if (s[j] == (char)(i + 'a')) {
        chmax(maxv, c);
        c = 0;
      } else {
        c++;
      }
    }
    chmax(maxv, c);
    chmin(ans, maxv);
  }
  cout << ans << endl;
}
