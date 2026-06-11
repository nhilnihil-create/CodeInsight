#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

bool dbgflag = false;

ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ll g = a[0];
  for (int i = 1; i < n; i++) {
    g = gcd(g, a[i]);
  }

  for (int i = 0; i < n; i++) {
    if (((a[i] - k) % g == 0) && (a[i] >= k)) {
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}
