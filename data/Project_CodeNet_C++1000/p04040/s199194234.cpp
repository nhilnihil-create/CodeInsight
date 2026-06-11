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

const int MAX = 510000;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(int i=2;i<MAX;i++) {
    fac[i] = fac[i-1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i-1] * inv[i] % MOD;
  }
}

ll COM(int n, int k) {
  if(n < k) return 0;
  if(n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

int main () {
  cin.tie(0);
  cout << setprecision(10);

  int h, w, a, b; cin >> h >> w >> a >> b;
  ll ans = 0;
  COMinit();

  REP(i, h-a) {
    ans = (ans + (COM(b-1 + i, i) * COM((w-b) + h-i - 2, h-i - 1)) % MOD) % MOD;
  }

  cout << ans << endl;
  
}
