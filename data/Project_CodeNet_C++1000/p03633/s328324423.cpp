#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  int n;
  cin >> n;
  vector<ll> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  ll ans = 1;
  for (int i = 0; i < n; ++i) {
    ans = lcm(ans, t[i]);
  }
  cout << ans << endl;
  return 0;
}
