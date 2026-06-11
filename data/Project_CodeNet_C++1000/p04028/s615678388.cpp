#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define REP(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define RREP(i, n) RFOR(i, n, 0)
#define MFOR(i, m) for(auto i=(m).begin();i!=(m).end();i++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((int)(x).size())

typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(vector<T> const& s) {
  REP(i, SZ(s)) {
    cout << s[i];
    if(i == SZ(s)-1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
}

int main () {
  cin.tie(0);
  cout << fixed << setprecision(10);

  int n; cin >> n;
  string s; cin >> s;
  int sz = SZ(s);

  vector<vector<ll>> dp(n+1, vector<ll>(n+1));
  dp[0][0] = 1;
    
  for(int i=0;i<n;++i) {
    for(int j=0;j<n+1;++j) {
      if(j == 0) {
        dp[i+1][j] += dp[i][j];
        dp[i+1][j+1] += 2*dp[i][j];
        dp[i+1][j+1] %= MOD;
      } else {
        if(j-1 >= 0) {
          dp[i+1][j-1] += dp[i][j];
          dp[i+1][j-1] %= MOD;
        }
        if(j+1 <= n) {
          dp[i+1][j+1] += 2*dp[i][j];
          dp[i+1][j+1] %= MOD;
        }
      }
    }
  }
  const ll inv2 = 500000004;
  for(int i=0;i<sz;++i) {
    dp[n][sz] *= inv2;
    dp[n][sz] %= MOD;
  }
  cout << dp[n][sz] << endl;
}