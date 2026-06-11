#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define freopen \
  if (0) freopen
#define cerr \
  if (0) cerr
#endif

#define fi first
#define se second

#define pb push_back
#define pp pop_back
#define mp make_pair

#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)

#define sqr(a) ((a)*1ll * (a))
#define sz(a) (int)a.size()
#define len(a) (int)a.length()
#define all(a) a.begin(), a.end()
#define nl '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pi;

const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;

int n;
string s;
int dp[5005][10010];

void solve() {
  cin >> n >> s;

  dp[0][0] = 1;
  rep(i, 1, n) {
    rep(j, 0, 10005) {
      int tmp = j > 0 ? dp[i - 1][j - 1] : dp[i - 1][j];
      dp[i][j] += (tmp + 2 * 1ll * dp[i - 1][j + 1]) % mod;
      dp[i][j] %= mod;
    }
  }

  cout << dp[n][len(s)];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen(".in", "r", stdin);

  solve();

  return 0;
}