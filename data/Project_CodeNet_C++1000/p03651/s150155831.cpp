#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  ll n, k, g, ans = 0, mx = 0;
  cin >> n >> k;
  vector<ll> a(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    mx = max(mx, a[i]);
    if (i == 0) g = a[0];
    g = gcd(g, a[i]);
  }

  if (k <= mx && k % g == 0)
    cout << "POSSIBLE" << endl;
  else
    cout << "IMPOSSIBLE" << endl;
  return 0;
}
