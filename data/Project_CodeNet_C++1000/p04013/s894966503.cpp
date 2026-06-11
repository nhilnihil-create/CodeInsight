#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define rep(i,n) for (int i = (0); i < (n); ++i)
#define rng(x) (x).begin(),(x).end()
#define rrng(x) (x).rbegin(),(x).rend()
#define show(x) cout << #x << " = " << (x) << endl;
#define show2(x,y) cout << #x << " = " << (x) << ", " << #y << " = " << (y) << endl;
#define show3(x,y,z) cout << #x << " = " << (x) << ", " << #y << " = " << (y) <<  ", " << #z << " = " << (z) << endl;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define uni(x) x.erase(unique(rng(x)),x.end())
#define SP << " " <<
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int mod = 1000000007;
const double EPS = 1e-9;
const int INF = 1<<30;
const ll INFLL = 1LL<<60;
//cout << fixed << setprecision(10);

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

ll x[55];
ll y[55];
ll dp[55][5050];

int main () {
  ll n, a;
  cin >> n >> a;
  rep(i,n) cin >> x[i];
  ll X = *max_element(x,x+n);
  rep(i,n) y[i] = x[i] - a;
  
  dp[0][n*X] = 1;
  rep(i,n+1) {
    rep(j,2*n*X+1) {
      if (dp[i][j] == 0) continue;
      dp[i+1][j] += dp[i][j];
      dp[i+1][j+y[i]] += dp[i][j];
    }
  }

  ll ans = dp[n][n*X] - 1;
  cout << ans << endl;
  return 0;
}