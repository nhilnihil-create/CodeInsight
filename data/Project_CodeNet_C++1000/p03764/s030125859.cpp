#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define fst first
#define snd second
#define ALL(obj) (obj).begin(), (obj).end()
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
//#define int long long int
const int MOD = 1000000007;
const ll LINF = (ll)1e20;
const int INF = 1e9;
const double EPS = 0.000000001;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  VL x(n), y(m);
  REP(i, n) cin >> x[i];
  REP(i, m) cin >> y[i];
  ll xsum = 0; ll ysum = 0;
  REP(i, n) {xsum += (i * x[i] - (n - i - 1) * x[i]) % MOD; xsum = xsum % MOD;}
  REP(i, m) {ysum += (i * y[i] - (m - i - 1) * y[i]) % MOD; ysum = ysum % MOD;}
  ll ans = xsum * ysum % MOD;
  ans = ans % MOD;
  out(ans);
  return 0;
}
