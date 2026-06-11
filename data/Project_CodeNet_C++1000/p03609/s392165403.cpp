#include <bits/stdc++.h>
#include <set>
#define rep(i,n) for (int i=0; i < (n); ++i)
#define all(a) a.begin(), a.end()
using ll = long long;
using namespace std;
 
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


// const double PI = acos(-1);

void solve() {
  int x,t; cin >> x >> t;
  int ans = x - t;
  if (ans > 0) {
    cout << ans << endl;
  }
  else {
    cout << 0 << endl;
  }
}

int main() {
  solve();
  return 0;
}
