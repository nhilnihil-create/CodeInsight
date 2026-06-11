#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define Rep(i,a,n) for (ll i = (a); i < (n); ++i)
const ll mod = 1e9+7;
const ll INF = 1e18;
#define All(a) (a).begin(),(a).end()
#define Pi acos(-1)
using Graph = vector<vector<ll>>;
using V = vector<ll>;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  chrono::system_clock::time_point start,end;
  start = chrono::system_clock::now();

  ll n, m;
  cin >> n >> m;
  vector<pair<ll,ll>> a(m);
  rep(i,m) {
    cin >> a[i].first >> a[i].second;
  }
  sort(All(a));
  V b(n);
  rep(i,m) {
    if (a[i].first == 1) {
      b[a[i].second-1] = 1;
    }
    if (a[i].second == n) {
      if (b[a[i].first-1] == 1) {
        cout << "POSSIBLE\n";
        return 0;  
      }
    }
  }
  cout << "IMPOSSIBLE\n";

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}