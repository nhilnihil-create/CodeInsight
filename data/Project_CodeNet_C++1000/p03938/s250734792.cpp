#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define rrep(i, a, b) for (int i = int(a) - 1; i >= b; i--)
#define sz(x) (int)(x).size()

using namespace std;
using ll = long long;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int main() {
  ll n;
  cin >> n;
  vector<ll> p(n);
  rep(i, 0, n) cin >> p[i];

  vector<ll> a(n, 0), b(n, 0);
  ll m = n + 10000;
  rep(i, 0, n) a[i] += (i * m);
  rep(i, 0, n) b[i] = a[n - i - 1] + 1;
  rep(i, 0, n) a[p[i] - 1] += i + 1;

  rep(i, 0, n) cout << a[i] << " ";
  cout << endl;
  rep(i, 0, n) cout << b[i] << " ";
  cout << endl;
}