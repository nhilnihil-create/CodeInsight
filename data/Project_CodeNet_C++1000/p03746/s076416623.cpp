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
const ll LINF = 1 << 30;

template<typename T>
void printv(vector<T> const& s) {
  REP(i, SZ(s)) {
    cout << s[i] << " ";
  }
  cout << endl;
}

int main () {
  cin.tie(0);
  cout << setprecision(10);

  int n, m; cin >> n >> m;
  vvi g(n);
  REP(i, m) {
    int a, b; cin >> a >> b;
    a--; b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  vector<bool> sel(n);
  sel[0] = 1;
  int pos = 0;
  vi ans1;
  ans1.pb(1);
  while(1) {
    bool upd = false;
    REP(i, SZ(g[pos])) {
      if(!sel[g[pos][i]]) {
        pos = g[pos][i];
        sel[pos] = 1;
        ans1.pb(pos+1);
        upd = true;
        break;
      }
    }
    if(!upd) break;
  }
  pos = 0;
  vi ans2;
  ans2.pb(1);
  while(1) {
    bool upd = false;
    REP(i, SZ(g[pos])) {
      if(!sel[g[pos][i]]) {
        pos = g[pos][i];
        sel[pos] = 1;
        ans2.pb(pos+1);
        upd = true;
        break;
      }
    }
    if(!upd) break;
  }
  reverse(ALL(ans2));

  cout << SZ(ans1) + SZ(ans2) - 1 << endl;
  REP(i, SZ(ans2)-1) {
    cout << ans2[i] << " ";
  }
  REP(i, SZ(ans1)) {
    cout << ans1[i];
    if(i == SZ(ans1)-1) cout << endl;
    else cout << " ";
  }
}
