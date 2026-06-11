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

//ll dp[i][j][k]: 1,..,i からj枚選んで合計をkにするような選び方の総数
ll dp[55][55][2550];
ll x[55];

int main () {
  int n, a;
  cin >> n >> a;
  rep(i,n) cin >> x[i];
  
  rep(i,55)rep(j,55)rep(k,2550) dp[i][j][k] = 0;
  dp[0][0][0] = 1;
  rep(i,50) {
    rep(j,50) {
      rep(k,2501) {
        if (dp[i][j][k] == 0) continue;
        dp[i+1][j][k] += dp[i][j][k];
        dp[i+1][j+1][k+x[i]] += dp[i][j][k];
      }
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += dp[n][i][i*a];
  }
  cout << ans << endl; 
  return 0;
}