#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
const ll mod = 1e9+7;
const ll INF = 1e18;
#define All(a) (a).begin(),(a).end()
#define Pi acos(-1)
using Graph = vector<vector<ll>>;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  chrono::system_clock::time_point start,end;
  start = chrono::system_clock::now();

  ll n, m;
  cin >> n >> m;
  vector<string> a(n);
  vector<string> b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];
  ll u = 0;

  rep(i,n-m+1) {
    rep(j,n-m+1) {
      if (a[i][j] == b[0][0]) {
        rep(k,m) {
          rep(l,m) {
            if (a[i+k][j+l] == b[k][l]) {
              ++u;
            }
          }
        }
        if (u == m*m) {
          cout << "Yes\n";
          return 0;  
        }
        else {
          u = 0;
        }
      }
    }
  }
  cout << "No\n";

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}