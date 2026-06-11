#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
int ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return 0;
}
ll factorial(ll n) {
  if (n == 1) {
    return 1;
  }
  ll ans = factorial(n-1);
  return ans*n;
}
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
  return (a/gcd(a, b))*b;
}
bool is_prime(ll n) {
  for (ll i = 2; i*i <= n; i++) {
    if (n%i == 0) return false;
  }
  return n != 1;
}
ll mod_pow(ll x, ll n, ll mod) {
  if (n == 0) return 1;
  ll res = mod_pow(x*x%mod, n/2, mod);
  if (n & 1) res = res * x % mod;
  return res;
}

int main() {
  ll n;
  cin >> n;
  vector <char> v(n);
  vector <char> u(n);
  rep(i, n) cin >> v.at(i);
  rep(i, n) cin >> u.at(i);
  vector <bool> flag(n);
  rep(i, n) {
    if (v.at(i) == u.at(i)) flag.at(i) = 1;
    else flag.at(i) = 0;
  }
  ll res;
  if (flag.at(0)) {
    res = 3;
    for (ll i = 1; i < n; i++) {
      if (flag.at(i)) {
        if (flag.at(i-1)) {
          res *= 2;
        } else {
          res *= 1;
        }
      } else {
        if (flag.at(i-1)) {
          res *= 2;
        } else {
          res *= 3;
        }
        i++;
      }
      res %= mod;
    }
  } else {
    res = 6;
    for (ll i = 2; i < n; i++) {
      if (flag.at(i)) {
        if (flag.at(i-1)) {
          res *= 2;
        } else {
          res *= 1;
        }
      } else {
        if (flag.at(i-1)) {
          res *= 2;
        } else {
          res *= 3;
        }
        i++;
      }
      res %= mod;
    }
  }
  cout << res << endl;
}