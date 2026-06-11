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
  ll l;
  cin >> l;
  vl a(n);
  REP(i, n) { cin >> a[i]; }

  int j = -1;
  REP(i, n - 1) {
    if (a[i] + a[i + 1] >= l)
      j = i;
  }
  if (j == -1) {
    cout << "Impossible" << endl;
    return 0;
  }
  cout << "Possible" << endl;

  REP(i, j) { cout << i + 1 << endl; }

  for (int i = n - 2; i > j; i--) {
    cout << i + 1 << endl;
  }
  cout << j + 1 << endl;
}
