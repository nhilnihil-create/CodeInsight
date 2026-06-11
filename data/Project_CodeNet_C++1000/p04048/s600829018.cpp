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

ll f(ll a, ll b) {
  if (b > a) {
    if (b % a == 0)
      return a * (2 * (b / a) - 1);
    return 2 * a * (b / a) + f(a, b % a);
  } else if (b < a) {
    if (a % b == 0)
      return b * (2 * (a / b) - 1);
    return 2 * b * (a / b) + f(a % b, b);
  } else {
    return a;
  }
}

int main() {
  ll n, x;
  cin >> n >> x;
  cout << n + f(x, n - x) << endl;
}
