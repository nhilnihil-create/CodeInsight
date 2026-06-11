#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef long double ld;

ll n, x;

ll f(ll a, ll b) {
  return b % a == 0 ? (2 * b / a - 1) * a : 2 * a * (b / a) + f(b % a, a);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n >> x;
  cout << n + f(x, n - x) << "\n";
}
