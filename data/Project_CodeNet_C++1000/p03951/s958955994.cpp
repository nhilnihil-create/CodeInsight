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

  int n;
  string s, t;
  cin >> n >> s >> t;

  rep(i, 0, n) {
    string ss = s.substr(i);
    string tt = t.substr(0, n - i);
    if (ss == tt) {
      cout << n + i << endl;
      return 0;
    }
  }

  cout << n * 2 << endl;
}
