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

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  chrono::system_clock::time_point start,end;
  start = chrono::system_clock::now();

  ll n;
  cin >> n;
  ll f = 0;
  ll t = 0;
  rep (i,n) {
    ll q;
    cin >> q;
    if (q%4 == 0) ++f;
    if (q%4 == 2) ++t;
  }
  n -= f*2;
  if (t == 0) --n;
  n -= t;
  if (n <= 0) cout << "Yes\n";
  else cout << "No\n";

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}