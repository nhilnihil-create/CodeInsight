#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cctype>

using namespace std;

#define REP(i,n) for(ll (i) = (0); (i) < (n); ++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define ALL(v) v.begin(),v.end()
#define Decimal fixed << setprecision(20)
#define SHOWP(x) cerr<<"["<<(x).FI<<", "<<(x).SE<<"]";
#define SHOWX(x) cerr<<#x<<": "<<x<<endl;
#define SHOWVEC(v, e) REP(i, e) cerr << (v[i]) << ' '; cerr << endl;
#define SHOW2D(a, h, w) REP(i, h){REP(j, w)cerr<<setw(3)<<(a[i][j])<<' ';cerr<<endl;}
constexpr int INF = 1 << 30 - 1;
constexpr long long LLINF = 1LL << 60;
constexpr long long MOD = 1000000007;

typedef long long ll;
typedef pair<ll, ll> P;


int main()
{
  int N;
  cin >> N;
  vector<ll> A(N), T(N);
  REP(i, N) cin >> A[i];
  REP(i, N) cin >> T[i];

  vector<bool> Af(N, false), Tf(N, false);
  for (int i = 1; i < N; i++) {
    if (A[i - 1] == A[i]) Af[i] = true;
  }
  for (int i = N - 2; i >= 0; i--) {
    if (T[i] == T[i + 1]) Tf[i] = true;
  }

  ll ans = 1;
  REP(i, N) {
    if (!Af[i] && !Tf[i]) ans *= (A[i] == T[i] ? 1 : 0);
    if ( Af[i] && !Tf[i]) ans *= (A[i] >= T[i] ? 1 : 0);
    if (!Af[i] &&  Tf[i]) ans *= (A[i] <= T[i] ? 1 : 0);
    if ( Af[i] &&  Tf[i]) (ans *= min(A[i], T[i])) %= MOD;
  }
  cout << ans << endl;
  return 0;
}