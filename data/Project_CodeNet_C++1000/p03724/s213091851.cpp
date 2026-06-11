#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  int n, a, b, m, ans = 0;
  cin >> n >> m;
  vector<ll> s(n);
  rep(i, m) {
    cin >> a >> b;
    a--, b--;
    s[a]++, s[b]++;
  }

  bool ok = true;
  for (ll t : s)
    if (t % 2) {
      ok = false;
      break;
    }

  cout << (ok ? "YES" : "NO") << endl;
  return 0;
}
