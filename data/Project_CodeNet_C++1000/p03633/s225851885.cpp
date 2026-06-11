#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
#define rep(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
using namespace std;

ll gcd(ll a, ll b) {
  if(a % b == 0) return b;
  return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
  return a / gcd(a,b) * b;
}

int main() {
  int n;
  cin >> n;
  vector<ll> v(n);
  rep(i, 0, n) cin >> v[i];
  ll m = v[0];
  rep(i, 1, n) {
    m = lcm(m, v[i]);
  }
  cout << m << "\n";
}