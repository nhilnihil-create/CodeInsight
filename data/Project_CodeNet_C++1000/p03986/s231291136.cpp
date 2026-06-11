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

  string x;
  cin >> x;
  int n = x.size();
  vector<int> s, t;

  if (x[0] == 'T')
    s.push_back(0);

  int first = x.find('S');

  if (first == -1) {
    cout << n << endl;
    return 0;
  }

  ll ans = first;
  int scount = 0;

  rep(i, first, n) {
    if (x[i] == 'S') {
      scount++;
    } else {
      if (scount == 0)
        ans++;
      else
        scount--;
    }
  }
  ans += scount;
  cout << ans << endl;
}
