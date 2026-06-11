//#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
// #define int ll
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
#ifdef int
const int INF = (1LL<<30);
#else
const ll INF = (1LL<<60);
#endif
const double PI = 3.14159265359;
const double EPS = 1e-12;
const int MOD = 1000000007;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int bit[100010], nn = 100010;

//0からi-1番目までの和
int sum(int i) {
  i++;
  int s = 0;
  while(i > 0) {
    s += bit[i];
    i -= i&-i;
  }
  return s;
}

//i番目(0-index)にxを加える
void add(int i, int x) {
  i++;
  while(i <= nn) {
    bit[i] += x;
    i += i&-i;
  }
}

VVI v;
int ans[100010];
signed main(void)
{
  int n, m;
  cin >> n >> m;
  REP(i, n) {
    int l, r;
    cin >> l >> r;
    ++r;
    v.PB({r-l, l, r});
  }
  sort(ALL(v));

  int idx = 0;
  FOR(i, 1, m+1) {
    int ans = n-idx;
    for(int j=0; j<=m; j+=i) ans += sum(j);
    cout << ans << endl;
    while(idx<n && v[idx][0] <= i) {
      add(v[idx][1], 1);
      add(v[idx][2], -1);
      ++idx;
    }
    // cout << "idx:" << idx << endl;
    // REP(j, m+1) cout << sum(j+1) << " "; cout << endl;
  }

  return 0;
}
