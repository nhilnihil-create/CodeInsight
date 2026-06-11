
#include <bits/stdc++.h>

#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX_NM = 100000, MOD = 1e9 + 7;
int n, m;
ll x[MAX_NM+20], y[MAX_NM+20];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> x[i];
  for (int i = 1; i <= m; ++i) cin >> y[i];

  ll xans = 0;
  for (ll i = 1; i <= n-1; ++i) {
    xans += i*(n-i)%MOD*(x[i+1]-x[i])%MOD;
    xans %= MOD;
  }
  ll yans = 0;
  for (ll i = 1; i <= m-1; ++i) {
    yans += i*(m-i)%MOD*(y[i+1]-y[i])%MOD;
    yans %= MOD;
  }

  ll ans = xans*yans%MOD;

  cout << ans << endl;

  return 0;
}
