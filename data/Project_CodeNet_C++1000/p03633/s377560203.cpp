#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
  return (a/gcd(a, b))*b;
}

int main() {
    ll n; cin >> n;
    ll res;
    rep(i, n) {
        ll t; cin >> t;
        if (i) res = lcm(res, t);
        else res = t;
    }
    cout << res << endl;
}