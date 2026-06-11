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
  string ans;
  cin >> n;
  REP(i, n) cin >> a[i];
  ll sum = 0;
  REP(i, n) sum += a[i];
  if (sum % 2 == 1) cout << "NO" << endl;
  if (sum % 2 == 0) cout << "YES" << endl;
  //   ll evenCount = 0, oddCount = 0;
  //   REP(i, n) {
  //     if (a[i] % 2 == 1) {
  //       oddCount++;
  //     } else {
  //       evenCount++;
  //     }
  //   }
  //   ll oddPair = oddCount / 2;
  //   oddCount -= 2 * oddPair;
  //   evenCount += oddPair;
  //   if (evenCount > 0 && oddCount > 0) {
  //     ans = "NO";
  //   } else if (evenCount > 0 && oddCount == 0) {
  //     ans = "YES";
  //   } else if (evenCount == 0 && oddCount > 0) {
  //     ans = "YES";
  //   } else if (evenCount == 0 && oddCount == 0) {
  //     ans = "NO";
  //   }
  //   cout << ans << endl;
  return 0;
}