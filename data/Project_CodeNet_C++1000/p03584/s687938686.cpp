#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define IN(a, b, x) (a<=x&&x<b)
#define MP make_pair
#define PB push_back
const int INF = (1LL<<30);
const ll LLINF = (1LL<<60);
const double PI = 3.14159265359;
const double EPS = 1e-12;
const int MOD = 1000000007;
#define int ll

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int a[100010], b[100010];
signed main(void)
{
  int n, k;
  cin >> n >> k;
  REP(i, n) cin >> a[i] >> b[i];

  int ret = 0;
  REP(j, n) {
    bool flag = true;
    REP(l, 30) {
      if((a[j]>>l)&1 && !((k>>l)&1)) {flag = false; break;}
    }
    if(flag) ret += b[j];
  }

  int ans = ret;
  REP(i, 30) {
    // kの上位ibit目が1 → そこを0にしてそこより下位のbitを1に
    if(k>>i&1) {
      int c = k&~(1LL<<i);
      c |= (1LL<<i)-1;
      // a[j]でbitが立っていてcでbitが立っていない → だめ
      int ret = 0;
      REP(j, n) {
        bool flag = true;
        REP(l, 30) {
          if((a[j]>>l)&1 && !((c>>l)&1)) {flag = false; break;}
        }
        if(flag) ret += b[j];
      }
      chmax(ans, ret);
    }
  }
  cout << ans << endl;

  return 0;
}