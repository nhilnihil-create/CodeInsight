
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;
const ll INF = 1LL << 62;
int main() {
  //
  ll n;
  cin >> n;
  vl a(3 * n);
  rep(i, 3 * n) { cin >> a[i]; }
  vl fsum(3 * n, 0), ssum(3 * n, 0);
  priority_queue<ll, vl, greater<ll>> first;
  priority_queue<ll> second;
  ll firstsum = 0;
  rep(i, n) {
    first.push(a[i]);
    firstsum += a[i];
  }
  fsum[n - 1] = firstsum;
  // cerr << firstsum << endl;
  for (int i = n; i <= 2 * n; i++) {
    first.push(a[i]);
    ll remove = first.top();
    first.pop();
    firstsum = firstsum + a[i] - remove;
    fsum[i] = firstsum;
  }
  ll secondsum = 0;
  for (int i = 3 * n - 1; i >= 2 * n; i--) {
    secondsum += a[i];
    second.push(a[i]);
  }
  ssum[2 * n] = secondsum;
  for (int i = 2 * n - 1; i >= n; i--) {
    second.push(a[i]);
    ll remove = second.top();
    second.pop();
    secondsum = secondsum + a[i] - remove;
    ssum[i] = secondsum;
  }
  // rep(i, 3 * n) { cerr << sum[i] << " "; }
  // cerr << endl;
  // rep(i, 3 * n) { cerr << fsum[i] << " "; }
  // cerr << endl;
  // rep(i, 3 * n) { cerr << ssum[i] << " "; }
  // cerr << endl;
  ll ans = fsum[n - 1] - ssum[n];
  for (int i = n + 1; i <= 2 * n; i++) {
    // ll f = sum[i - 1] - fsum[i - 1];
    // ll s = sum[3 * n - 1] - sum[i - 1] - ssum[i];
    ans = max(ans, fsum[i - 1] - ssum[i]);
  }
  cout << ans << endl;
  return 0;
}
