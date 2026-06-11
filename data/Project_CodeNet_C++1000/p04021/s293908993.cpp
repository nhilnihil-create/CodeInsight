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
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  REP(i, n) {
    int _a;
    cin >> _a;
    a[i] = make_pair(_a, i + 1);
  }
  sort(ALL(a));
  int ans = 0;
  REP(i, n) {
    if (i % 2 != 0)
      continue;
    if ((i + 1) % 2 != a[i].second % 2)
      ans++;
  }
  cout << ans << endl;
}
