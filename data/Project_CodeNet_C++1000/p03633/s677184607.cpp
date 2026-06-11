#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  ll n, t, ans = 1;
  cin >> n;
  rep(i, n) {
    cin >> t;
    ans = lcm(ans, t);
  }
  cout << ans << endl;
  return 0;
}
