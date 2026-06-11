#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
typedef long long int ll;
typedef long double ld;
#define rep(i,a,n) for (ll i = (a); i < (n); ++i)
const ll mod = 1e9+7;
const ll INF = 1e18;
#define All(a) (a).begin(),(a).end()
#define Pi acos(-1)

int digit(ll n) {
  int res = 0;
  while(n > 0) {
    ++res;
    n /= 10;
  }
  return res;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  chrono::system_clock::time_point start,end;
  start = chrono::system_clock::now();

  ll n;
  cin >> n;
  ll ans = INF;
  rep(i,1,sqrt(n)+1) {
    if (n%i == 0) {
      ll tmp = max(digit(i),digit(n/i));
      ans = min(ans,tmp);
    }
  }
  cout << ans << '\n';


  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}
