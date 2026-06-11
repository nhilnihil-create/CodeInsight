#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define rep1(i,n) for (int i=1; i<=(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define fst first
#define scd second
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, m; cin >> n >> m;
  ll ans = 0, M = 1e9+7;
  if (abs(n-m) <= 1) {
    ll a = 1, b = 1;
    rep1(i,n) a = (a * i) % M;
    rep1(i,m) b = (b * i) % M;
    if (n==m) ans = ((a*a % M) * 2) % M;
    else ans = (a * b) % M;
  }
  cout << ans << endl;
  return 0;
}