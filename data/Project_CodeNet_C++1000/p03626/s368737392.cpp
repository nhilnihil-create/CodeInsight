#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll n; cin >> n;
  string s, t; cin >> s >> t;
  ll res;
  if (s.at(0) == t.at(0)) {
    res = 3;
    bool flag = 1;
    for (ll i = 1; i < n; i++) {
      if (s.at(i) == t.at(i)) {
        if (flag) res *= 2;
        else res *= 1;
        flag = 1;
        res %= mod;
      } else {
        if (flag) res *= 2;
        else res *= 3;
        flag = 0;
        i++;
        res %= mod;
      }
    }
  } else {
    res = 6;
    bool flag = 0;
    for (ll i = 2; i < n; i++) {
      if (s.at(i) == t.at(i)) {
        if (flag) res *= 2;
        else res *= 1;
        flag = 1;
        res %= mod;
      } else {
        if (flag) res *= 2;
        else res *= 3;
        flag = 0;
        i++;
        res %= mod;
      }
    }
  }
  cout << res << endl;
}