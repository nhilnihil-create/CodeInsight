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
const ll INF = 1ll << 50;

template<typename T>
void printv(vector<T> const& s) {
  REP(i, SZ(s)) {
    cout << s[i] << " ";
  }
  cout << endl;
}

vvll g;

void warshall_floyd() {
  int n = g.size();
  REP(i, n) {
    REP(j, n) {
      REP(k, n) {
        g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
      }
    }
  }
}

signed main () {
  cin.tie(0);
  cout << setprecision(10);

  int n; cin >> n;
  vvll a(n);
  g.resize(n);
  REP(i, n) {
    g[i].resize(n);
    a[i].resize(n);
    REP(j, n) {
      cin >> g[i][j];
      a[i][j] = g[i][j];
    }
  }

  warshall_floyd();

  ll ans = 0;

  REP(i, n) {
    FOR(j, i+1, n) {
      if(a[i][j] > g[i][j]) {
        cout << -1 << endl;
        return 0;
      } else {
        bool ok = true;
        REP(k, n) {
          if(k != i && k != j && g[i][k] + g[k][j] == a[i][j]) ok = false;
        }
        if(ok) ans += a[i][j];
      }
    }
  }

  cout << ans << endl;

  
}
