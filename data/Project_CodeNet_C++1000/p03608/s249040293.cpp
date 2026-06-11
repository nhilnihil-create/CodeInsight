#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
const ll mod = 1000000007;
const ll inf = 1LL<<60;

int main()
{
  int n,m,p;cin>>n>>m>>p;
  vector<ll> r(p);
  rep(i, p) {
    cin>>r[i];
    r[i]--;
  }
  sort(r.begin(),r.end());
  vector<vector<ll>> d(n, vector<ll>(n, inf));
  rep(i, n) d[i][i] = 0;
  rep(i, m) {
    ll a,b,c; cin>>a>>b>>c; a--; b--;
    d[a][b] = c;
    d[b][a] = c;
  }
  rep(k, n) rep(i, n) rep(j, n) {
    d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
  }
  ll ans = inf;
  do {
    ll tmp = 0;
    for (int i=1; i<p; i++) {
      tmp += d[r[i-1]][r[i]];
    }
    ans = min(ans, tmp);
  } while (next_permutation(r.begin(), r.end()));
  cout << ans << endl;

  return 0;
}
