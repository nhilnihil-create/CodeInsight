#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

#define REP(i,n) for(ll (i) = (0); (i) < (n); ++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define ALL(v) v.begin(),v.end()
#define INF 1100000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007
#define Decimal fixed << setprecision(20)
#define SHOWP(x) cerr<<"["<<(x).FI<<", "<<(x).SE<<"]";
#define SHOWX(x) cerr<<#x<<": "<<x<<endl;
#define SHOWVEC(v, e) REP(i, e) cerr << (v[i]) << ' '; cerr << endl;
#define SHOW2D(a, h, w) REP(i, h){REP(j, w)cerr<<setw(3)<<(a[i][j])<<' ';cerr<<endl;}

typedef long long ll;
typedef pair<ll, ll> P;


int main()
{
  int N, K; cin >> N >> K;
  vector<ll> a(N);
  REP(i, N) cin >> a[i];
  vector<ll> ps(a), as(a);
  REP(i, N) ps[i] = max(0LL, ps[i]);
  REP(i, N - 1) {
    as[i + 1] += as[i];
    ps[i + 1] += ps[i];
  }

  auto psum = [](vector<ll>& v, int l, int r)->ll {
    if (r < l) return 0;
    else if (l == 0) return v[r];
    else return v[r] - v[l - 1];
  };
  ll ans = 0;
  for (int i = 0; i + K - 1 < N; i++) {
    ll x = psum(ps, 0, i - 1);
    ll y = max(0LL, psum(as, i, i + K - 1));
    ll z = psum(ps, i + K, N - 1);
    ans = max(ans, x + y + z);
  }
  cout << ans << endl;
  return 0;
}