#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n, a, b; cin >> n >> a >> b;
  vector <ll> v(n);
  rep(i, n) cin >> v.at(i);
  ll res = 0;
  for (ll i = 1; i < n; i++) {
    res += min(a*(v.at(i)-v.at(i-1)), b);
  }
  cout << res << endl;
}