#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
#define fi first
#define se second
#define INF 1000000009
#define LLINF 1000000000000000009LL
using ll = long long;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll b = 0;
  rep(i,n) {
    cin >> a[i];
    b += a[i];
  }
  ll s = n * (n + 1) / 2;
  if (b % s != 0) {
    cout << "NO" << endl;
    return(0);
  }
  ll x = b / s;
  vector<ll> d(n);
  rep(i,n) {
    d[i] = a[i] - a[(i+1)%n];
    d[i] += x;
  }
  bool ok = true;
  rep(i,n) {
    if (d[i] < 0 || d[i] % n != 0) ok = false;
  }
  cout << (ok ? "YES" : "NO") << endl;
  return(0);
}
