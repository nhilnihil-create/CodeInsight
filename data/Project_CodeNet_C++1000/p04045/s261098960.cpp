#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  int n, k;
  int d[15] = {};
  cin >> n >> k;

  REP(i, k) {
    int x;
    cin >> x;
    d[x] = 1;
  }

  ll ans = n;

  while (true) {
    bool flag = true;
    string s = to_string(ans);
    for (auto c : s) {
      if (d[c - '0'] == 1) {
        flag = false;
        break;
      }
    }

    if (flag) break;
    ans++;
  }
  cout << ans << endl;
}