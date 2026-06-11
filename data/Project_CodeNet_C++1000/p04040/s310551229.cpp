#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define freopen \
  if (0) freopen
#define cerr \
  if (0) cerr
#endif

#define f first
#define s second

#define pb push_back
#define pp pop_back
#define mp make_pair

#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)

#define sqr(a) ((a)*1ll * (a))
#define sz(a) (int)a.size()
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

vector<int> fact;
vector<int> fact_inv;

int powm(int n, int p) {
  int res = 1;
  while (p > 0) {
    if (p & 1) {
      res = (res * 1ll * n) % mod;
    }
    p >>= 1;
    n = (n * 1ll * n) % mod;
  }
  return res;
}

int inv(int n) { return powm(n, mod - 2) % mod; }

void precalc_fact(int n) {
  fact.resize(n + 1);
  fact_inv.resize(n + 1);
  fact[0] = 1;
  fact_inv[0] = 1;
  rep(i, 1, n) { 
    fact[i] = (fact[i - 1] * 1ll * i) % mod; 
    fact_inv[i] = (fact_inv[i - 1] * 1ll * inv(i)) % mod;
  }
}

int choose(int n, int r) {
  int inv_fact = ((fact_inv[r] * 1ll * fact_inv[n - r]) % mod);
  return (fact[n] * 1ll * inv_fact) % mod;
}

int calc_ways(int x1, int y1, int x2, int y2) {
  int h_steps = x2 - x1;
  int v_steps = y2 - y1;
  return choose(h_steps + v_steps, v_steps);
}

void solve() {
  int h, w, a, b;
  cin >> h >> w >> a >> b;

  precalc_fact(h + w - 2);
  int res = 0;

  rep(i, b, w - 1) {
    int combs1 = calc_ways(0, 0, h - a - 1, i);
    int combs2 = calc_ways(h - a, i, h - 1, w - 1);
    int combs = (combs1 * 1ll * combs2) % mod;
    res = (res * 1ll + combs) % mod;
  }

  cout << res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen(".in", "r", stdin);

  solve();

  return 0;
}