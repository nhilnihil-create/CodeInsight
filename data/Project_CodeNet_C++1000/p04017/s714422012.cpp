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

int n, d, q;
int x[100010];
int dp[100010][20];
int a, b;

void solve() {
  cin >> n;
  rep(i, 1, n)
    cin >> x[i];
  cin >> d;

  rep(i, 1, n) {
    int l = i + 1, r = n + 1;
    while (l < r) {
      int m = (l + r) >> 1;
      if (x[m] - x[i] <= d) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    dp[i][0] = l - 1;
  }

  rep(k, 1, 17) {
    rep(i, 1, n) {
      dp[i][k] = dp[dp[i][k - 1]][k - 1];
    }
  }

  cin >> q;
  rep(i, 0, q - 1) {
    cin >> a >> b;
    if (a > b) swap(a, b);
    int days = 0;

    per(k, 17, 0) {
      if (dp[a][k] < b) {
        days += (1<<k);
        a = dp[a][k];
      }
    }

    a = dp[a][0];
    days++;

    cout << days << nl;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen(".in", "r", stdin);

  solve();

  return 0;
}