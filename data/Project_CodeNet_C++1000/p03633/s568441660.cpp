#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll gcd(ll a, ll b) {
  if (a % b == 0) return b;
  else return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
  return a / gcd(a,b) * b;
}

int main() {
  int n; cin >> n;
  vector<ll> t(n);
  rep(i,n) cin >> t[i];
  ll c = 1;
  rep(i,n) {
    c = lcm(t[i], c);
  }
  cout << c << endl;
  return 0;
}