#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vi ans(2 * n - 1, 0);
  if (x == 1 || x == 2 * n - 1) {
    cout << "No" << endl;
    return 0;
  }
  if (x == 2 || x == 2 * n - 2) {
    ans[(2 * n - 1) / 2] = x;
    ans[(2 * n - 1) / 2 - 1] = 1;
    ans[(2 * n - 1) / 2 + 1] = 2 * n - 1;
    int c = 2 == x ? 3 : 2;
    REP(i, 2 * n - 1) {
      if (ans[i] != 0) {
        continue;
      }
      ans[i] = c;
      c++;
      if (c == x)
        c++;
    }
  } else {
    ans[(2 * n - 1) / 2] = x;
    ans[(2 * n - 1) / 2 - 1] = 1;
    ans[(2 * n - 1) / 2 + 1] = 2 * n - 1;
    ans[(2 * n - 1) / 2 - 2] = 2 * n - 2;
    ans[(2 * n - 1) / 2 + 2] = 2;
    int c = 3 == x ? 4 : 3;
    REP(i, 2 * n - 1) {
      if (ans[i] != 0)
        continue;
      ans[i] = c;
      c++;
      if (c == x) {
        c++;
      }
    }
  }
  cout << "Yes" << endl;
  REP(i, 2 * n - 1) { cout << ans[i] << endl; }
}
