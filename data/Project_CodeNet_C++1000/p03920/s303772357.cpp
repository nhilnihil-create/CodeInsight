#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
using namespace std;
typedef long long ll;
const ll INF = 1e15;
int main() {
  ll n;
  cin >> n;
  ll mx, sum = 0;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  FOR(i, 1, n) {
    sum += i;
    if (sum < n && n <= sum + i + 1) {
      mx = i + 1;
      sum += mx;
      break;
    }
  }
  ll diff = sum - n;
  FOR(i, 1, mx + 1) {
    if (i == diff) continue;
    cout << i << endl;
  }
  return 0;
}