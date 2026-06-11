#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int INF = 100100100;
const double PI = 3.14159265358979323846;
typedef long long ll;
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define REP(i, n) for (ll i = 0; i < (n); ++i)

int main() {
  ll n, a[100001] = {0};
  ll res = 0;
  cin >> n;
  REP(i, n) cin >> a[i];
  ll minPlus = 0, minMinus = 0;
  ll sumPlus = 0, sumMinus = 0;
  REP(i, n) {
    sumPlus += a[i];
    if (i % 2 == 0 && sumPlus <= 0) {
      minPlus += 1 - sumPlus;
      sumPlus = 1;
    } else if (i % 2 == 1 && sumPlus >= 0) {
      minPlus += sumPlus + 1;
      sumPlus = -1;
    }
  }
  REP(i, n) {
    sumMinus += a[i];
    if (i % 2 == 0 && sumMinus >= 0) {
      minMinus += sumMinus + 1;
      sumMinus = -1;
    } else if (i % 2 == 1 && sumMinus <= 0) {
      minMinus += 1 - sumMinus;
      sumMinus = 1;
    }
  }
  res = min(minPlus, minMinus);
  cout << res << endl;
  return 0;
}