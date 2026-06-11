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

map< pi, int > squares;

void solve() {
  int h, w, n;
  int x, y;
  cin >> h >> w >> n;

  rep(l, 1, n) {
    cin >> x >> y;
    rep(i, x - 1, x + 1) {
      rep(j, y - 1, y + 1) {
        if (i <= 1 || j <= 1 || i >= h || j >= w) {
          continue;
        }
        squares[mp(i, j)]++;
      }
    }
  }

  vector<ll> res(10, 0);
  res[0] = (h - 2) * 1ll * (w - 2) - (ll)squares.size();
  for (auto it : squares) {
    res[it.second]++;
  }

  rep(i, 0, 9) {
    cout << res[i] << nl;
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
