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

  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  rep(i,d-b) cout << 'U';
  rep(i,c-a+1) cout << 'R';
  rep(i,d-b+1) cout << 'D';
  rep(i,c-a+1) cout << 'L';
  cout << 'U';
  cout << 'L';
  rep(i,d-b+1) cout << 'U';
  rep(i,c-a+1) cout << 'R';
  rep(i,d-b+1) cout << 'D';
  rep(i,c-a) cout << 'L';
  cout << '\n';

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}